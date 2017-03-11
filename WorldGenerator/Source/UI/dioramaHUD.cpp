//
//  dioramaHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "dioramaHUD.hpp"

dioramaHUD::dioramaHUD (GraphicsEngine* graph, PhysicsEngine* phys): background(graph), back(graph, phys) {
    // backdrop
    background.scaleTo(glm::vec3(1.5, 3, 0.0));
    background.moveTo(glm::vec3(-2, 0.0, 0.1));
    
    // back button
    items.push_back(&back);
    items.at(0)->scaleTo(glm::vec3(0.5, 0.15, 0));
    items.at(0)->moveTo(glm::vec3(-2.075, -0.75, 0.2));
    items.at(0)->update();

    // input
    gamepad = InputManager::getGamepadHandle();
    mouse = InputManager::getMouseHandle();
}

dioramaHUD::~dioramaHUD () {
    
}

void dioramaHUD::hide () {
    background.setAlpha(0);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        box->setAlpha (0);
    });
}

void dioramaHUD::show () {
    background.setAlpha(0.5);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        box->setAlpha (1);
    });
}

void dioramaHUD::update () {
    background.update();
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->update();
    });
}
