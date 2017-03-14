//
//  Diorama.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Diorama_hpp
#define Diorama_hpp

#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

class Diorama: public GameObject {
    public:
        Diorama (GraphicsEngine* g);
       ~Diorama ();
    
        virtual void update (State state) override;
    
    private:
        GraphicsObject* graphics;
    
        Mouse* mouse;
    
        glm::vec3 velocity;
};

#endif /* Diorama_hpp */
