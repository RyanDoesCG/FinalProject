//
//  UIDelegate.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIDelegate.hpp"

UIDelegate::UIDelegate (GraphicsEngine* graph, PhysicsEngine* phys, Game* g):
    mainMenu (graph, phys),
    optionsMenu(graph, phys),
    dHUD     (graph, phys),
    pHUD     (graph, phys) {
    
    game = g;
    
    gamepad = InputManager::getGamepadHandle();
    mouse   = InputManager::getMouseHandle();
    
    state = main_menu;
}

UIDelegate::~UIDelegate () {
    
}

void UIDelegate::update() {
    switch (state) {
        case main_menu: {
            mainMenu.show();
            optionsMenu.hide();
            dHUD.hide();
            pHUD.hide();
            
            mainMenu.update();
            
            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (mainMenu.dioramas .isSelected()) { state = diorama; }
                if (mainMenu.planets  .isSelected()) { state = planet; }
                if (mainMenu.options  .isSelected()) { state = options; }
                if (mainMenu.quit     .isSelected()) { state = over; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
            
        case diorama: {
            mainMenu.hide();
            dHUD.show();
            pHUD.hide();
            
            dHUD.update();
            
            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (dHUD.back.isSelected()) { state = main_menu; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
            
        case planet: {
            mainMenu.hide();
            dHUD.hide();
            pHUD.show();
            
            pHUD.update();
            
            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (pHUD.back.isSelected()) { state = main_menu; }
                
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                mouse->leftButtonHandled();
            }
            break;
        }
            
        case options: {
            mainMenu.hide();
            optionsMenu.show();
            dHUD.hide();
            pHUD.hide();
            
            optionsMenu.update();
            
            if (mouse->leftButtonDown() || gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
                if (optionsMenu.back.isSelected()) { state = main_menu; }
                
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
