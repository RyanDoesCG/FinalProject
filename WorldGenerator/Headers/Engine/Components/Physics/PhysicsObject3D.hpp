//
//  PhysicsObject3D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsObject3D_hpp
#define PhysicsObject3D_hpp

#include "PhysicsObject.hpp"

class PhysicsObject3D: public PhysicsObject {
    public:
        PhysicsObject3D ();
       ~PhysicsObject3D ();
    
        virtual void simulate (double time) = 0;

    private:
        glm::vec3 position;
        glm::vec3 velocity;
        glm::vec3 dampening;
};

#endif /* PhysicsObject3D_hpp */
