/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D partial disk
 * 
 */
#ifndef     _PARTIALDISK_H_
#define     _PARTIALDISK_H_

#include "triMesh.h"

/** 
 * PartialDisk object
 * 
 */
class PartialDisk : public TriMesh {

    public:
	PartialDisk(int nb);
        virtual ~PartialDisk(){};
        

};

#endif
