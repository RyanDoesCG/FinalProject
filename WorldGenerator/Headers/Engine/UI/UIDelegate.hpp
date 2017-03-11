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

#include "GameObject.hpp"

#include "Menu.hpp"
#include "HUD.hpp"

class UIDelegate: public GameObject {
    public:
        UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys);
       ~UIDelegate ();
    
        virtual void update () override;
    
    private:
        enum UIState {
            main_menu,
            diorama,
            planet,
            options,
            hidden
        };
    
        UIState state;
        Menu mainMenu;
        HUD  gameHud;
};

#endif /* UIDelegate_hpp */
