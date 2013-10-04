/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D sphere
 * 
 */
#ifndef     _SPHERE_H_
#define     _SPHERE_H_

#include "triMesh.h"

/** 
 * Sphere object
 * 
 */
class Sphere : public TriMesh {

    public:
	Sphere(GLint nb);
        virtual ~Sphere(){};
        

};

#endif
