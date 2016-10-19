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
#include "../GLM/vec3.hpp"
#include <iostream>

class GraphicsComponent;
class PhysicsComponent;
class InputComponent;

/**
 *  GameObject Class
 *
 */
class GameObject {
    public:
        GameObject();
        ~GameObject();
    
        void setGraphics (GraphicsComponent* graphics);
        void setPhysics  (PhysicsComponent*  physics);
        void setInput    (InputComponent*    input);

        virtual void update();
    
        glm::mat4 position;
    
        void rotateLeft  ();
        void rotateRight ();
        void grow        ();
        void shrink      ();
    
    protected:
    
        GraphicsComponent* graphics;
        PhysicsComponent*  physics;
        InputComponent*    input;

};

#endif /* GameObject_hpp */
