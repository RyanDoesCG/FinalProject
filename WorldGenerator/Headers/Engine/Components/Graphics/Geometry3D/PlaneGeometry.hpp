//
//  PlaneGeometry.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PlaneGeometry_hpp
#define PlaneGeometry_hpp

#include "Geometry.hpp"

class PlaneGeometry: public Geometry {
    public:
        PlaneGeometry (const int size);
       ~PlaneGeometry ();
};

#endif /* PlaneGeometry_hpp */
