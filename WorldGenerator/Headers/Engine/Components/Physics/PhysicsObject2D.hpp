//
//  PhysicsObject2D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsObject2D_hpp
#define PhysicsObject2D_hpp

#include "PhysicsObject.hpp"

class PhysicsObject2D: public PhysicsObject {
    public:
        PhysicsObject2D ();
       ~PhysicsObject2D ();
    
        virtual void simulate (double time) = 0;
    
    private:
        glm::vec2 position;
        glm::vec2 velocity;
        glm::vec2 dampening;
};

#endif /* PhysicsObject2D_hpp */
