/**
 * @author Clement Garnier
 * @date   Oct 2012
 * 
 *  Defines a 3D model from a OFF file
 * 
 */
#ifndef     _OFF_H_
#define     _OFF_H_

#include "triMesh.h"

/** 
 * Off_Loader object
 * 
 */
class Off_Loader : public TriMesh {

    public:
	Off_Loader(const string& path);
        virtual ~Off_Loader(){};
    private:
        /**
              * Divide a polygon to triangles and apply color
              * @param elems Point index vector
              * @param color Color of the polygon
              */
        void triangulize(vector<int> elems, Color color);

};

#endif
