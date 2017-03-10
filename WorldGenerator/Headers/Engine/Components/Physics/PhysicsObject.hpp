//
//  PhysicsObject.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsObject_hpp
#define PhysicsObject_hpp

class PhysicsObject {
    public:
        PhysicsObject () {}
       ~PhysicsObject () {}
    
        virtual void simulate (double time) = 0;
    
        glm::vec3 position;
        glm::vec3 velocity;
        glm::vec3 dampening;
};

#endif /* PhysicsObject_hpp */
