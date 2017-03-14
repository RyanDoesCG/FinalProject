//
//  EngineTest.hpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef EngineTest_hpp
#define EngineTest_hpp

#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

class EngineTest: public GameObject {
    public:
        EngineTest (GraphicsEngine* g, PhysicsEngine* p);
       ~EngineTest ();
    
        virtual void update (State state) override;
    
    private:
        GraphicsObject* graphics;
        PhysicsObject2D* collider;
    
        Mouse* mouse;
    
        glm::vec3 velocity;
};

#endif /* EngineTest_hpp */
