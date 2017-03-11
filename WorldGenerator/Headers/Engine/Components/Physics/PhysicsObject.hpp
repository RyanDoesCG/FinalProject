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
    
        virtual glm::vec3 pos () = 0;
    
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 velocity;
        glm::vec3 dampening;
    
        virtual void scaleTo (glm::vec3 s) = 0;
        virtual void moveTo  (glm::vec3 p) = 0;
    
        bool colliding;
        int  type;
    
        // 0 indicates AABB
};

#endif /* PhysicsObject_hpp */
