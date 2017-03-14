//
//  UIDelegate.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UIDelegate_hpp
#define UIDelegate_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "InputManager.hpp"
#include "GameObject.hpp"
#include "Menu.hpp"
#include "dioramaHUD.hpp"
#include "Options.hpp"
#include "planetHUD.hpp"
#include "Game.hpp"

class UIDelegate: public GameObject {
    public:
        UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys, Game* g);
       ~UIDelegate ();
    
        virtual void update (State state) override;
    
    private:
        enum UIState {
            main_menu,
            diorama,
            planet,
            options,
            hidden,
            over
        };
    
        UIState     uiState;
        Menu        mainMenu;
        Options     optionsMenu;
        dioramaHUD  dHUD;
        planetHUD   pHUD;
    
        Gamepad* gamepad;
        Mouse* mouse;
    
        Game* game;
};

#endif /* UIDelegate_hpp */
