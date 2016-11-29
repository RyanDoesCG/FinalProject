//
//  OptionsMenu.cpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/OptionsMenu.hpp"

OptionsMenu::OptionsMenu (float width, float height, Game* game):
    Menu(width, height, game) {
        
    // ABOUT
    about.label = "about";
    about.index = items.size();
    items.push_back(about);
        
    // CONTROLLER
    controller.label = "controller";
    controller.index = items.size();
    items.push_back(controller);

    // QUALITY
    quality.label = "quality";
    quality.index = items.size();
    items.push_back(quality);

    
    // RESOLUTION
    resolution.label = "resolution";
    resolution.index = items.size();
    items.push_back(resolution);
        
    selectedItem = items.size() - 1;
}

OptionsMenu::~OptionsMenu () {
    
}

void OptionsMenu::handleEvents() {
    Menu::handleEvents();

    if (!isHidden) {
        // select
        if (keyboard->isKeyDown(GLFW_KEY_ENTER)) {
            switch (selectedItem) {
 
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
