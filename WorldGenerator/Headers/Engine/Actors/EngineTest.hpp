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

class EngineTest: public GameObject {
    public:
        EngineTest (GraphicsEngine* g, PhysicsEngine* p);
       ~EngineTest ();
    
    private:
        virtual void update () override;
        GraphicsObject* triangle;
        PhysicsObject2D* collider;
    
};

#endif /* EngineTest_hpp */
