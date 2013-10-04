/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D disk
 * 
 */
#ifndef     _DISK_H_
#define     _DISK_H_

#include "triMesh.h"

/** 
 * Disk object
 * 
 */
class Disk : public TriMesh {

    public:
	Disk(int nb);
        virtual ~Disk(){};
        

};

#endif
