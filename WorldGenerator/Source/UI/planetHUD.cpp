//
//  planetHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "planetHUD.hpp"

planetHUD::planetHUD  (GraphicsEngine* graph, PhysicsEngine* phys): GameHUD (graph, phys) {}
planetHUD::~planetHUD () {}

void planetHUD::hide () {
    background.setAlpha(0);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        box->setAlpha (0);
    });
}

void planetHUD::show () {
    background.setAlpha(0.5);
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        box->setAlpha (1);
    });
}

void planetHUD::update () {
    background.update();
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->update();
    });
}
