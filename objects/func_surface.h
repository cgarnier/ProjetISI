/**
 * @author Clement Garnier
 * @date   Oct 2012
 *
 *  Define 3D surfaces from f(x,y) = z
 */

#ifndef FUNC_SURFACE_H_
#define FUNC_SURFACE_H_

#include "objects/triMesh.h"


typedef GLfloat (*func)(const GLfloat&, const GLfloat&);

/*
 * FuncSurface Object
 */
class FuncSurface: public TriMesh {
public:
	FuncSurface(GLint nbx, GLint nby, GLfloat minx, GLfloat maxx, GLfloat miny,
			GLfloat maxy, vector<func> funcs);

	virtual ~FuncSurface();
private:

	/**
	 * adds a math function to the mesh
	 * @param func a function pointer whith x, y float parameters
	 */
	void addFunction(GLfloat (*func)(const GLfloat&, const GLfloat&));

	/**
	 * Rescale the functions between -1;1 on the Z axe.
	 *
	 */
	void scaleZ();

	/**
	 * Initialize a color map
	 *
	 */
	void initColorMap();
	GLint _nbx;
	GLint _nby;
	GLfloat _minx;
	GLfloat _maxx;
	GLfloat _miny;
	GLfloat _maxy;
	GLfloat _minz;
	GLfloat _maxz;

	GLfloat _pasx;
	GLfloat _pasy;
	vector<Color> _colorMap;
	int _count;
};

/**
 * Mathematics function f(x,y) = exp(-(x²/2 + y²/2)) * cos(2*x² + 2*y²)
 * @param x Value on x's axe
 * @param y Value on y's axe
 */
GLfloat func_expcos(const GLfloat& x, const GLfloat& y);

/**
 * Mathematics function f(x,y) = x * exp(-x² - y²)
 * @param x Value on x's axe
 * @param y Value on y's axe
 */
GLfloat func_expxy(const GLfloat& x, const GLfloat& y);

/**
 * Mathematics function f(x,y) = sin(x) - sin(y) + sin(x*10)/10 - sin(y*10)/10
 * @param x Value on x's axe
 * @param y Value on y's axe
 */
GLfloat func_sinsin(const GLfloat& x, const GLfloat& y);
#endif /* FUNC_SURFACE_H_ */
