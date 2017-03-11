//
//  dioramaHUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef dioramaHUD_hpp
#define dioramaHUD_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"

#include "InputManager.hpp"
#include "Mouse.hpp"
#include "UIBoxBackground.hpp"
#include "UIBox.hpp"

class dioramaHUD: public GameObject {
    public:
        dioramaHUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~dioramaHUD ();
    
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


#endif /* dioramaHUD_hpp */
