/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D cylinder
 * 
 */
#ifndef     _CYLINDER_H_
#define     _CYLINDER_H_

#include "triMesh.h"

/** 
 * Cylinder object
 * 
 */
class Cylinder : public TriMesh {

    public:
	Cylinder(int nb);
        virtual ~Cylinder(){};
        

};

#endif
