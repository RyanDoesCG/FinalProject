//
//  PhysicsObject3D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsObject3D_hpp
#define PhysicsObject3D_hpp

#include "glm.hpp"
#include "PhysicsObject.hpp"

class PhysicsObject3D: public PhysicsObject {
    public:
        PhysicsObject3D ();
       ~PhysicsObject3D ();
    
        virtual void simulate (double time) = 0;
        virtual void isColliding (PhysicsObject3D* other) = 0;

};

#endif /* PhysicsObject3D_hpp */
