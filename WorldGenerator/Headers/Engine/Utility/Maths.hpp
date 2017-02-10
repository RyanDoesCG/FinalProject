//
//  Maths.hpp
//  WorldGenerator
//
//  Created by user on 10/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Maths_hpp
#define Maths_hpp

#include "../../glm/glm.hpp"

using namespace glm;

static float vectorDistance (vec3 a, vec3 b) {
    float distX = b.x - a.x;
    float distY = b.y - a.y;
    float distZ = b.z - a.z;
    
    return (sqrt((distX * distX) + (distY * distY) + (distZ * distZ)));
}

#endif /* Maths_hpp */
