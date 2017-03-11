//
//  planetHUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef planetHUD_hpp
#define planetHUD_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"

#include "InputManager.hpp"
#include "Mouse.hpp"
#include "UIBoxBackground.hpp"
#include "UIBox.hpp"

class planetHUD: public GameObject {
    public:
        planetHUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~planetHUD ();
    
        virtual void update () override;
    
        void hide ();
        void show ();
    
        UIBox back;
    
    public:
        UIBoxBackground background;
        std::vector<UIBox*> items;
    
        Gamepad* gamepad;
        Mouse* mouse;
};


#endif /* planetHUD_hpp */
