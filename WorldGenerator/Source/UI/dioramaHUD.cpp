//
//  dioramaHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "dioramaHUD.hpp"

dioramaHUD::dioramaHUD  (GraphicsEngine* graph, PhysicsEngine* phys): GameHUD(graph, phys) {
    
}

dioramaHUD::~dioramaHUD () {}

void dioramaHUD::hide () {
    background.isHidden = true;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        //box->setAlpha(0);
        box->isHidden = true;
    });
}

void dioramaHUD::show () {
    background.isHidden = false;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        //box->setAlpha(1);
        box->isHidden = false;
    });
}

void dioramaHUD::update (State state) {
    background.update(state);
    
    for (UIBox* box : items)
        box->update(state);
}
