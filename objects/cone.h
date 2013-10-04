/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D cone
 * 
 */
#ifndef     _CONE_H_
#define     _CONE_H_

#include "triMesh.h"

/** 
 * Cone object
 * 
 */
class Cone : public TriMesh {

    public:
	Cone(GLint nb);
        virtual ~Cone(){};
        

};

#endif
