/**
 * @author Clement Garnier
 * @date   Oct 2012
 *
 *  Defines a 3D sphere by recursive subdivision
 *
 */
#ifndef     _SPHERESUB_H_
#define     _SPHERESUB_H_

#include "triMesh.h"
#include "Bench.h"

/** 
 * SphereSub object
 * 
 */
class SphereSub: public TriMesh {

public:
	SphereSub(int nb);
	virtual ~SphereSub() {
	}
	;
private:
	/*
	 * Subdivide recursively a triangle
	 * @param v1 the first vertex id of the triangle
	 * @param v2 the second vertex id of the triangle
	 * @param v3 the the third vertex id of the triangle
	 * @param depth the depth of recursion
	 */
	void subdivide(int v1, int v2, int v3, long depth);

};

#endif
