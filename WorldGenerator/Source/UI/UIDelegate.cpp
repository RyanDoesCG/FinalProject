//
//  UIDelegate.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIDelegate.hpp"

bool hideUI = false;

UIDelegate::UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys, Game* g):
    mainMenu    (graph, phys),
    dHUD        (graph, phys, g->getDiorama()),
    pHUD        (graph, phys, g->getPlanet()) {
    
    game = g;
    
    keyboard = InputManager::getKeyboardHandle();
    gamepad = InputManager::getGamepadHandle();
    mouse   = InputManager::getMouseHandle();
    
    uiState = main_menu;
    
    mainMenu.show();
    dHUD.hide();
    pHUD.hide();
}

UIDelegate::~UIDelegate () {
    
}

void UIDelegate::update(State state) {
    mainMenu.update(state);
    dHUD.update(state);
    pHUD.update(state);

    switch (uiState) {
        case main_menu: {
            mainMenu.show();
            dHUD.hide();
            pHUD.hide();

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (mainMenu.dioramas .isSelected()) { uiState = diorama;  game->state = VIEW;  game->showDiorama();  }
                if (mainMenu.planets  .isSelected()) { uiState = planet; game->state = VIEW;  game->showPlanet();  }
                if (mainMenu.quit     .isSelected()) { uiState = over; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
        
        case infinite: {
            mainMenu.hide();
            dHUD.hide();
            pHUD.hide();
            break;
        }
            
        case diorama: {
            mainMenu.hide();
            pHUD.hide();
            
            
            if (!hideUI) {
                dHUD.show();
            }
            
            if (hideUI) {
                dHUD.hide();
            }

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (dHUD.back.isSelected()) { uiState = main_menu; game->state = MENU; }
                
                //gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                //mouse->leftButtonHandled();
            }
            
            if (keyboard->isKeyDown(GLFW_KEY_SPACE)) {
                keyboard->keyHandled(GLFW_KEY_SPACE);
                hideUI = !hideUI;
            }
            
            break;
        }
            
        case planet: {
            mainMenu.hide();
            dHUD.hide();
            
            if (!hideUI) {
                pHUD.show();
            }
            
            if (hideUI) {
                pHUD.hide();
            }

            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (pHUD.back.isSelected()) { uiState = main_menu; game->state = MENU; }
                
                //gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                //mouse->leftButtonHandled();
            }
            
            if (keyboard->isKeyDown(GLFW_KEY_SPACE)) {
                keyboard->keyHandled(GLFW_KEY_SPACE);
                hideUI = !hideUI;
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
