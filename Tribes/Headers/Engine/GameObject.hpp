/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GameObject_hpp
#define GameObject_hpp

#include "GraphicsComponent.hpp"
#include "PhysicsComponent.hpp"
#include "glm/vec3.hpp"
#include <iostream>

class GameObject {
    public:
        GameObject();
        ~GameObject();
    
        void setGraphics (GraphicsComponent* graphics);
        void setPhysics  (PhysicsComponent*  physics);

    
        void update();
    

    private:
        glm::vec3* position;
    
        GraphicsComponent* graphics;
        PhysicsComponent*  physics;

};

#endif /* GameObject_hpp */
