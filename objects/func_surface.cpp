/*
 * func_surface.cpp
 *
 *  Created on: 12 oct. 2012
 *      Author: clement
 */

#include "func_surface.h"

FuncSurface::FuncSurface(GLint nbx, GLint nby, GLfloat minx, GLfloat maxx,
		GLfloat miny, GLfloat maxy, vector<func> funcs) :
		TriMesh(), _nbx(nbx), _nby(nby), _minx(minx), _maxx(maxx), _miny(miny), _maxy(
				maxy), _pasx((maxx - minx) / nbx), _pasy((maxy - miny) / nby), _minz(
				-1.0), _maxz(1.0), _count(0) {
	_name = "Fonction de surface";
	if (_nbx < 0 || _nby < 0)
		throw "Le nombre d'echantillons sur x et y doit etre positif";
	if (_maxx - _minx < 0 || _maxy - _miny < 0)
		throw "Domaine de definition invalide";

	// Color map
	initColorMap();

	// Ajout des surfaces
	for (int i = 0; i < funcs.size(); ++i) {
		addFunction(funcs.at(i));
	}

	// Mise a l'echelle sur Z -1,1
	scaleZ();

	computeNormalsT();
	computeNormalsV();

}

void FuncSurface::initColorMap() {
	Color c;
	c.push_back(0.0);
	c.push_back(1);
	c.push_back(0);
	c.push_back(0.6);
	_colorMap.push_back(c);
	c[0] = 1;
	c[1] = 0;
	c[2] = 0;
	_colorMap.push_back(c);
	c[0] = 0;
	c[1] = 0;
	c[2] = 1;

	_colorMap.push_back(c);
	c[0] = 0.5;
	c[1] = 0.5;
	c[2] = 0;

	_colorMap.push_back(c);
	c[0] = 0;
	c[1] = 0.5;
	c[2] = 0.5;

	_colorMap.push_back(c);
	c[0] = 0.5;
	c[1] = 0;
	c[2] = 0.5;

	_colorMap.push_back(c);
}

//// Fonctions math
GLfloat func_expcos(const GLfloat& x, const GLfloat& y) {
	return glm::exp(-(x * x / 2 + y * y / 2)) * glm::cos(2 * x * x + 2 * y * y);
}
GLfloat func_expxy(const GLfloat& x, const GLfloat& y) {
	return x * glm::exp(-x * x - y * y);
}
GLfloat func_sinsin(const GLfloat& x, const GLfloat& y) {
	return glm::sin(x) - glm::sin(y) + glm::sin(x * 10) / 10
			- glm::sin(y * 10) / 10;
}

void FuncSurface::scaleZ() {
	GLfloat factZ = 2 / (_maxz - _minz);
	for (int i = 0; i < _vertices.size(); ++i) {
		_vertices.at(i).z = _vertices.at(i).z * factZ;
	}
}
void FuncSurface::addFunction(GLfloat (*func)(const GLfloat&, const GLfloat&)) {
	int offset = _vertices.size();

	// Facteurs de mise a l'echelle
	GLfloat factX = 2 / (_maxx - _minx);
	GLfloat factY = 2 / (_maxy - _miny);

	GLfloat z;
	for (int x = 0; x < _nbx; ++x) {
		for (int y = 0; y < _nby; ++y) {
			z = func(_minx + x * _pasx, _miny + y * _pasy);

			// Recherche des extremum
			if (z > _maxz)
				_maxz = z;
			if (z < _minz)
				_minz = z;

			addVertex((_minx + x * _pasx) * factX, (_miny + y * _pasy) * factY,
					z);

			if (x < _nbx - 1 && y < _nby - 1) {
				GLint pt1 = offset + x * _nby + y;
				GLint pt2 = offset + x * _nby + y + 1;
				GLint pt3 = offset + (x + 1) * _nby + y;
				GLint pt4 = offset + (x + 1) * _nby + y + 1;

				addTriangle(pt1, pt3, pt2);
				addTriangleColor(_colorMap[_count % _colorMap.size()]);
				addTriangle(pt2, pt3, pt4);
				addTriangleColor(_colorMap[_count % _colorMap.size()]);

			}
		}
	}
	_count++;
}

FuncSurface::~FuncSurface() {
	// TODO Auto-generated destructor stub
}

