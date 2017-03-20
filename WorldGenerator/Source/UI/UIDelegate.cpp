//
//  UIDelegate.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIDelegate.hpp"

UIDelegate::UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys, Game* g):
    mainMenu    (graph, phys),
    optionsMenu (graph, phys),
    dHUD        (graph, phys, g->getDiorama()),
    pHUD        (graph, phys) {
    
    game = g;
    
    gamepad = InputManager::getGamepadHandle();
    mouse   = InputManager::getMouseHandle();
    
    uiState = infinite;
}

UIDelegate::~UIDelegate () {
    
}

void UIDelegate::update(State state) {
    mainMenu.update(state);
    optionsMenu.update(state);
    dHUD.update(state);
    pHUD.update(state);

    switch (uiState) {
        case main_menu: {
            mainMenu.show();
            optionsMenu.hide();
            dHUD.hide();
            pHUD.hide();

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (mainMenu.dioramas .isSelected()) { uiState = diorama; /*dHUD.diorama = game->makeNewDiorama();*/ game->state = VIEW; /* game->showDiorama(); */ }
                if (mainMenu.planets  .isSelected()) { uiState = planet;  /*pHUD.planet = game->makeNewPlanet();*/ game->state = VIEW; /* game->showPlanet(); */ }
                if (mainMenu.options  .isSelected()) { uiState = options; }
                if (mainMenu.quit     .isSelected()) { uiState = over; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
        
        case infinite: {
            mainMenu.hide();
            optionsMenu.hide();
            dHUD.hide();
            pHUD.hide();
            break;
        }
            
        case diorama: {
            mainMenu.hide();
            optionsMenu.hide();
            dHUD.show();
            pHUD.hide();

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (dHUD.back.isSelected()) { uiState = main_menu; game->state = MENU; }
                
                //gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                //mouse->leftButtonHandled();
            }
            break;
        }
            
        case planet: {
            mainMenu.hide();
            optionsMenu.hide();
            dHUD.hide();
            pHUD.show();

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (pHUD.back.isSelected()) { uiState = main_menu; game->state = MENU; }
                
                //gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                //mouse->leftButtonHandled();
            }
            break;
        }
            
        case options: {
            mainMenu.hide();
            optionsMenu.show();
            dHUD.hide();
            pHUD.hide();

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (optionsMenu.back.isSelected()) { uiState = main_menu; game->state = MENU; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
            
        case hidden: {
            break;
        }
        
        case over: {
            game->stop ();
            break;
        }
            
        default: break;
    }
}
