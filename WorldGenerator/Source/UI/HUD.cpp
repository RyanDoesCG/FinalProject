//
//  HUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "HUD.hpp"

HUD::HUD (GraphicsEngine* graph, PhysicsEngine* phys): background(graph) {
    // backdrop
    background.scaleTo(glm::vec3(1.5, 3, 0.0));
    background.moveTo(glm::vec3(-2, 0.0, 0.1));
    
    // dioarama generator
    items.push_back(UIBox(graph, phys));
    items.at(0).scaleTo(glm::vec3(1, 0.15, 0));
    items.at(0).moveTo(glm::vec3(-2.075, 0.75, 0.2));
    items.at(0).update();
    
    // planet generator
    items.push_back(UIBox(graph, phys));
    items.at(1).scaleTo(glm::vec3(1, 0.15, 0));
    items.at(1).moveTo(glm::vec3(-2.075,  0.25, 0.2));
    items.at(1).update();
    
    // options
    items.push_back(UIBox(graph, phys));
    items.at(2).scaleTo(glm::vec3(1, 0.15, 0));
    items.at(2).moveTo(glm::vec3(-2.075, -0.25, 0.2));
    items.at(2).update();
    
    // quit
    items.push_back(UIBox(graph, phys));
    items.at(3).scaleTo(glm::vec3(1, 0.15, 0));
    items.at(3).moveTo(glm::vec3(-2.075, -0.75, 0.2));
    items.at(3).update();
    
    // input
    gamepad = InputManager::getGamepadHandle();
    mouse = InputManager::getMouseHandle();
}

HUD::~HUD () {
    
}

void HUD::hide () {
    background.setAlpha(0);
    
    for_each(items.begin(), items.end(), [](UIBox box) {
        box.setAlpha (0);
    });
}

void HUD::show () {
    background.setAlpha(0.5);
    
    for_each(items.begin(), items.end(), [](UIBox box) {
        box.setAlpha (1);
    });
}

void HUD::update () {
    background.update();
    
    for_each(items.begin(), items.end(), [](UIBox box) {
        box.update();
    });
}
