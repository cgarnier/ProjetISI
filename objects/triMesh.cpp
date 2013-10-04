#include "triMesh.h"

#include <glm/gtc/type_ptr.hpp>

TriMesh::TriMesh() :
		Object3D() {
	_name = "TriMesh";
}
TriMesh::~TriMesh(){

}

void TriMesh::addVertex(Vertex v) {
	extendBoundingBox(v);
	_vertices.push_back(v);
}
void TriMesh::addVertex(double x, double y, double z) {
	addVertex(Vertex(x, y, z));
}
void TriMesh::addTriangle(Triangle t) {
	_triangles.push_back(t);
}
void TriMesh::addTriangle(int v1, int v2, int v3) {
	Triangle t;
	t.push_back(v1);
	t.push_back(v2);
	t.push_back(v3);
	addTriangle(t);
}
void TriMesh::addTriangleColor(Color c) {
	_trianglesColor.push_back(c);
}
void TriMesh::addNormalT(Normal n) {
	_normalsT.push_back(n);
}
void TriMesh::addNormalV(Normal n) {
	_normalsV.push_back(n);
}

Vertex TriMesh::getVertex(int i) {
	return _vertices[i];
}

void TriMesh::computeBoundingBox() {
	if (_vertices.size() < 1)
		return;

	_bBoxMax = _vertices[0];
	_bBoxMin = _vertices[0];
	for (unsigned int i = 0; i < _vertices.size(); ++i)
		extendBoundingBox(_vertices[i]);
}

void TriMesh::computeNormalsT() {
	_normalsT.empty();

	// Compute a normal for each triangle
	// and put it in normalsT vector.

	for (unsigned int t = 0; t < _triangles.size(); ++t) {
		addNormalT(computeNormalOf(_triangles.at(t)));
	}

}

void TriMesh::computeNormalsV(GLfloat angle_threshold) {
	_normalsV.empty();

	// Compute a normal for each vertex of each triangle
	// and put it in normalsV vector.
	// Each normal is the average of adjacent triangle normals.
	// Only normals whose angle with the current triangle normal
	// is below the angle_threshold is taken into account.


	angle_threshold = glm::radians(angle_threshold);

	// Indexation des normals en fonction des sommets
	// Pour chaque sommets, une liste de normal suceptible de d'avoir une influance sur la normal final
	vector < vector<GLint> > IdOfAdjTriangle;
	IdOfAdjTriangle.resize(_vertices.size());

	for (GLint j = 0; j < _triangles.size(); ++j) {
		for (GLint i = 0; i < 3; ++i)
			IdOfAdjTriangle[_triangles[j][i]].push_back(j);

	}

	// Pour chaque triangles
	for (GLint t = 0; t < _triangles.size(); ++t) {

		//Pour chaque point du triangle
		for (GLint pt = 0; pt < 3; ++pt) {
			Normal normalFinal(0.0, 0.0, 0.0);
			GLint cpt = 0;
			// Normal des 2 triangles
			glm::vec3 vecAB = _normalsT.at(t);

			for (vector<GLint>::iterator it =
					IdOfAdjTriangle[_triangles.at(t).at(pt)].begin();
					it != IdOfAdjTriangle[_triangles.at(t).at(pt)].end();
					++it) {
				glm::vec3 vecAC = _normalsT.at(*it);

				// Angle entre les normals inferieur a 70 ?
				GLfloat scalaire = glm::dot(vecAB, vecAC);
				if (scalaire >= glm::cos(angle_threshold)) {
					normalFinal += _normalsT[*it];
					cpt++;
				}

			}

			// Moyenne des normals
			normalFinal /= cpt;

			// Ajout de la normal
			addNormalV(normalFinal);
		}
	}
}

Normal TriMesh::computeNormalOf(Triangle triangle) {
	Vertex a = _vertices.at(triangle.at(0));
	Vertex b = _vertices.at(triangle.at(1));
	Vertex c = _vertices.at(triangle.at(2));

	glm::vec3 vecAB = a - b;
	glm::vec3 vecAC = a - c;

	glm::vec3 vecN = glm::cross(vecAB, vecAC);
	vecN = glm::normalize(vecN);

	Normal n(vecN.x, vecN.y, vecN.z);
	return n;
}

double TriMesh::normalize() {
	glm::vec3 size = _bBoxMax - _bBoxMin;
	glm::vec3 c = getBoundingBoxCenter();
	double scale = 2 / max(size.x, max(size.y, size.z));

	for (unsigned int i = 0; i < _vertices.size(); ++i) {
		_vertices[i] += c;
		_vertices[i] *= scale;
	}

	_bBoxMin += c;
	_bBoxMin *= scale;
	_bBoxMax += c;
	_bBoxMax *= scale;

	return scale;
}

std::string TriMesh::toString() {
	ostringstream oss;
	oss << "[" << _name << " v:" << _vertices.size() << ", t:"
			<< _triangles.size() << "]";
	return oss.str();
}

void TriMesh::toOStream(std::ostream& out) const {
	Object3D::toOStream(out);
	out << "   v: " << _vertices.size() << std::endl;
	out << "   t: " << _triangles.size() << std::endl;
}

void TriMesh::draw(bool flipnormals) {
	unsigned int i, t;
	Normal n;

	// Detection de la methode de colorisation
	bool smooth, colorOnVertices = false;
	bool colorOnTriangles = false;
	if (_triangles.size() == _trianglesColor.size())
		colorOnTriangles = true;
	// @TODO Vertex color support

	GLint mode[1];
	glGetIntegerv(GL_SHADE_MODEL, mode);
	smooth = mode[0] == GL_SMOOTH && _normalsV.size() == _triangles.size() * 3;

	if (smooth) {
		glBegin(GL_TRIANGLES);
		for (t = 0; t < _triangles.size(); ++t) {

			// Couleur
			if (colorOnTriangles)
				glColor4f(_trianglesColor[t][0], _trianglesColor[t][1],
						_trianglesColor[t][2], _trianglesColor[t][3]);

			for (i = 0; i < 3; i++) {
				n = _normalsV[3 * t + i];
				if (flipnormals)
					n *= -1;
//        glNormal3fv(&n[0]);
				glNormal3fv(glm::value_ptr(n));
				glVertex3fv(glm::value_ptr(_vertices[_triangles[t][i]]));
			}
		}
		glEnd();
	} else {
		glBegin(GL_TRIANGLES);
		for (t = 0; t < _triangles.size(); ++t) {
			n = _normalsT[t];
			if (flipnormals)
				n *= -1;

			// Couleur
			if (colorOnTriangles)
				glColor4f(_trianglesColor[t][0], _trianglesColor[t][1],
						_trianglesColor[t][2], _trianglesColor[t][3]);

			glNormal3fv(glm::value_ptr(n));
			for (i = 0; i < 3; i++) {
				glVertex3fv(glm::value_ptr(_vertices[_triangles[t][i]]));
			}
		}
		glEnd();
	}

}

void TriMesh::drawNormals(bool flipnormals) {
	unsigned int i, t;
	bool smooth;
	glm::vec3 p, n;

	GLint mode[1];
	glGetIntegerv(GL_SHADE_MODEL, mode);
	smooth = mode[0] == GL_SMOOTH && _normalsV.size() == _triangles.size() * 3;

	glColor3f(1, 1, 1);
	if (smooth) {
		for (i = 0; i < _normalsV.size(); ++i) {
			n = _normalsV[i];
			if (flipnormals)
				n *= -1;
			glNormal3fv(glm::value_ptr(n));
			n /= 10;
			glBegin(GL_LINES);
			glVertex3fv(glm::value_ptr(_vertices[_triangles[i / 3][i % 3]]));
			glVertex3fv(
					glm::value_ptr(_vertices[_triangles[i / 3][i % 3]] + n));
			glEnd();
		}
	} else {
		for (t = 0; t < _triangles.size(); ++t) {
			p = _vertices[_triangles[t][0]] + _vertices[_triangles[t][1]]
					+ _vertices[_triangles[t][2]];
			p /= 3;
			n = _normalsT[t];
			if (flipnormals)
				n *= -1;
			glNormal3fv(glm::value_ptr(n));
			n /= 10;
			glBegin(GL_LINES);
			glVertex3fv(glm::value_ptr(p));
			glVertex3fv(glm::value_ptr(p + n));
			glEnd();
		}
	}
}

void TriMesh::drawVertices() {
	glPointSize(3.);
	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < _vertices.size(); ++i)
		glVertex3fv(glm::value_ptr(_vertices[i]));
	glEnd();
}
