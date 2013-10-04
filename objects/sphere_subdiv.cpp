
#include "sphere_subdiv.h"

using namespace std;
/**
 * SphereSub Object
 *
 */
SphereSub::SphereSub(int nb) :
		TriMesh() {
	_name = "Sphere par subdiv";

	if(nb < 0) nb =1;

	// Id des points
	int i0, i1, i2, i3, i4, i5;

	// Forme de base
	glm::vec3 v0(1.0, 0, 0);
	glm::vec3 v1(0, 0, -1);
	glm::vec3 v2(-1, 0, 0);
	glm::vec3 v3(0, 0, 1);
	glm::vec3 v4(0, 1, 0);
	glm::vec3 v5(0, -1, 0);

	int offset = _vertices.size();
	addVertex(v0);
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
	addVertex(v4);
	addVertex(v5);

	i0 = offset;
	i1 = offset + 1;
	i2 = offset + 2;
	i3 = offset + 3;
	i4 = offset + 4;
	i5 = offset + 5;

	int depth = nb;

	// Subdivition des triangles de la forme de base
	subdivide(i0, i1, i4, depth);
	subdivide(i1, i2, i4, depth);
	subdivide(i2, i3, i4, depth);
	subdivide(i3, i0, i4, depth);
	subdivide(i1, i0, i5, depth);
	subdivide(i2, i1, i5, depth);
	subdivide(i3, i2, i5, depth);
	subdivide(i0, i3, i5, depth);


	computeNormalsT();
	computeNormalsV();

}

/*
 * Algorithme de subdivision recursive adapte de
 * http://www.glprogramming.com/red/chapter02.html
 *
 */
void SphereSub::subdivide(int i1, int i2, int i3, long depth) {
	Vertex v12, v23, v31;
	int i12, i23, i31;
	GLint i;

	// Condition d'arret
	if (depth == 0) {
		addTriangle(i1, i2, i3);
		return;
	}

	// Calcul du milieu de chaque sommets
	v12.x = _vertices[i1].x + _vertices[i2].x;
	v23.x = _vertices[i2].x + _vertices[i3].x;
	v31.x = _vertices[i3].x + _vertices[i1].x;

	v12.y = _vertices[i1].y + _vertices[i2].y;
	v23.y = _vertices[i2].y + _vertices[i3].y;
	v31.y = _vertices[i3].y + _vertices[i1].y;

	v12.z = _vertices[i1].z + _vertices[i2].z;
	v23.z = _vertices[i2].z + _vertices[i3].z;
	v31.z = _vertices[i3].z + _vertices[i1].z;

	v12 = glm::normalize(v12);
	v23 = glm::normalize(v23);
	v31 = glm::normalize(v31);

	// Recherche des points deja existant pour eviter les doublons
	// et que le smooth fonctionne
	bool v12Found = false, v23Found = false, v31Found = false;
	for (int i = 0; i < _vertices.size(); ++i) {
		if (_vertices[i] == v12) {
			i12 = i;
			v12Found = true;
		}
		if (_vertices[i] == v23) {
			i23 = i;
			v23Found = true;
		}
		if (_vertices[i] == v31) {
			i31 = i;
			v31Found = true;
		}

	}
	if (!v12Found) {
		i12 = _vertices.size();
		addVertex(v12);
	}
	if (!v23Found) {
		i23 = _vertices.size();
		addVertex(v23);
	}
	if (!v31Found) {
		i31 = _vertices.size();
		addVertex(v31);
	}

	// Subdivision des nouveau triangles
	subdivide(i1, i12, i31, depth - 1);
	subdivide(i2, i23, i12, depth - 1);
	subdivide(i3, i31, i23, depth - 1);
	subdivide(i12, i23, i31, depth - 1);

}
