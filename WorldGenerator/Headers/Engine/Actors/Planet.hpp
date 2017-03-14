//
//  Planet.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Planet_hpp
#define Planet_hpp

#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

class Planet: public GameObject {
    public:
        Planet (GraphicsEngine* g);
       ~Planet ();
    
        virtual void update (State state) override;
    
    private:
        GraphicsObject* graphics;
    
        Mouse* mouse;
    
        glm::vec3 velocity;
};

#endif /* Planet_hpp */
