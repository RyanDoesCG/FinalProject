//
//  AACollisionBox2D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef AACollisionBox2D_hpp
#define AACollisionBox2D_hpp

#include "PhysicsObject2D.hpp"
#include <string>

class AACollisionBox2D: public PhysicsObject2D {
    public:
        AACollisionBox2D (glm::vec2 scale);
       ~AACollisionBox2D ();
    
        virtual void simulate (double time) override;
        virtual bool isColliding (PhysicsObject2D* other) override;
    
        virtual void scaleTo (glm::vec3 s) override;
        virtual void moveTo  (glm::vec3 p) override;
    
        virtual glm::vec3 pos () override;
    
        std::string string ();

    private:
        float width;
        float height;
};

#endif /* AACollisionBox2D_hpp */
