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
                case 0: game->setState(RUNNING); break;
                case 1: game->setState(RUNNING); break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
            hide();
        }
    }
}
