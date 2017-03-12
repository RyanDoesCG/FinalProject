//
//  Cursor.hpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Cursor_hpp
#define Cursor_hpp

#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

class Cursor: public GameObject {
    public:
        Cursor (GraphicsEngine* g, PhysicsEngine* p);
       ~Cursor ();
    
        virtual void update () override;
    
    private:
        GraphicsObject* quad;
        PhysicsObject2D* collider;
    
        Gamepad* gamepad;
        Mouse* mouse;
    
        float lastXoffset;
        float lastYoffset;
};

#endif /* Cursor_hpp */
