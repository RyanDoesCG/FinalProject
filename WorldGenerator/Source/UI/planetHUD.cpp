//
//  planetHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "planetHUD.hpp"

planetHUD::planetHUD (GraphicsEngine* graph, PhysicsEngine* phys): background(graph), back(graph, phys) {
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

planetHUD::~planetHUD () {
    
}

void planetHUD::hide () {
    background.setAlpha(0);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->setAlpha (0);
    });
}

void planetHUD::show () {
    background.setAlpha(0.5);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->setAlpha (1);
    });
}

void planetHUD::update () {
    background.update();
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->update();
    });
}
