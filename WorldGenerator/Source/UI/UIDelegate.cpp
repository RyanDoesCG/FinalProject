//
//  UIDelegate.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIDelegate.hpp"

UIDelegate::UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys):
    mainMenu(graph, phys),
    gameHud(graph, phys) {
        
    mainMenu.show();
    gameHud.show();
    
    state = main_menu;
}

UIDelegate::~UIDelegate () {
    
}

void UIDelegate::update() {
    mainMenu.update();
    gameHud.update();
    
    switch (state) {
        case main_menu: {
            mainMenu.show();
            gameHud.hide();
            break;
        }
            
        case diorama: {
            mainMenu.hide();
            gameHud.show();
            break;
        }
            
        case planet: {
            mainMenu.hide();
            gameHud.show();
            break;
        }
            
        case options: {
            break;
        }
            
        case hidden: {
            break;
        }
            
        default: break;
    }
}
