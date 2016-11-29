//
//  SeedMenu.cpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/SeedMenu.hpp"

SeedMenu::SeedMenu (float width, float height, Game* game):
    Menu(width, height, game) {
    
    // CUSTOM SEED
    customSeed.label = "custom seed";
    customSeed.index = items.size();
    items.push_back(customSeed);
    
    // RANDOM SEED
    randomSeed.label = "random seed";
    randomSeed.index = items.size();
    items.push_back(randomSeed);
    
    selectedItem = items.size()-1;
}

SeedMenu::~SeedMenu () {
    
}

void SeedMenu::handleEvents() {
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
