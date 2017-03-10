//
//  PhysicsObject2D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsObject2D_hpp
#define PhysicsObject2D_hpp

#include "glm.hpp"
#include "PhysicsObject.hpp"

class PhysicsObject2D: public PhysicsObject {
    public:
        PhysicsObject2D ();
       ~PhysicsObject2D ();
    
        virtual void simulate (double time) = 0;
        virtual bool isColliding (PhysicsObject2D* other) = 0;

};

#endif /* PhysicsObject2D_hpp */
