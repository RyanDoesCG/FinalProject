//
//  EngineTest.hpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef EngineTest_hpp
#define EngineTest_hpp

#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"

class EngineTest: GameObject {
    public:
        EngineTest (GraphicsEngine* g);
       ~EngineTest ();
    
    private:
    
        virtual void update () override;
    
        GraphicsObject* triangle;
        //PhysicsObject2D* AACollisionBox2D;
    
};

#endif /* EngineTest_hpp */
