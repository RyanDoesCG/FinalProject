//
//  LoadMenu.cpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/UI/LoadMenu.hpp"

LoadMenu::LoadMenu (float width, float height, Game* game):
    Menu(width, height, game) {
    
    // EXAMPLE 3
    example2.label = "example save 3:   31/12/1999";
    example2.index = items.size();
    items.push_back(example2);
    
    // EXAMPLE 2
    example2.label = "example save 2:   31/12/2003";
    example2.index = items.size();
    items.push_back(example2);
    
    // EXAMPLE 1
    example1.label = "example save 1:   31/12/2007";
    example1.index = items.size();
    items.push_back(example1);
    
    selectedItem = items.size() - 1;

}

LoadMenu::~LoadMenu () {
    
}

void LoadMenu::handleEvents() {
    Menu::handleEvents();
    
    if (!isHidden) {
        // select
        if (keyboard->isKeyDown(GLFW_KEY_ENTER)) {
            switch (selectedItem) {
                case 0: std::cout << "custom seed" << std::endl; break;
                case 1: std::cout << "random seed" << std::endl; break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
        }
    }
    
    // back
    if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {
        for (int i = 0; i < children.size(); i++) { children[i]->hide(); }
        hide();
    }
}
