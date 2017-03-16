//
//  dioramaHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "dioramaHUD.hpp"

dioramaHUD::dioramaHUD  (GraphicsEngine* graph, PhysicsEngine* phys):
    GameHUD   (graph, phys),
    amplitude (graph, phys),
    example1  (graph, phys),
    example2  (graph, phys),
    example3  (graph, phys),
    example4  (graph, phys) {
    //amplitude.scaleTo(glm::vec3(1, 1, 1));
    amplitude.moveTo(glm::vec3(-2, 1.25, 0.1));
    example1.moveTo(glm::vec3(-2, 0.75, 0.1));
    example2.moveTo(glm::vec3(-2, 0.25, 0.1));
    example3.moveTo(glm::vec3(-2, -0.25, 0.1));
    example4.moveTo(glm::vec3(-2, -0.75, 0.1));
}

dioramaHUD::~dioramaHUD () {}

void dioramaHUD::hide () {
    background.isHidden = true;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        //box->setAlpha(0);
        box->isHidden = true;
    });
    
    amplitude.deactivatePhysics();
    amplitude.isHidden = true;
    
    example1.deactivatePhysics();
    example1.isHidden = true;
    
    example2.deactivatePhysics();
    example2.isHidden = true;
    
    example3.deactivatePhysics();
    example3.isHidden = true;
    
    example4.deactivatePhysics();
    example4.isHidden = true;
}

void dioramaHUD::show () {
    background.isHidden = false;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        //box->setAlpha(1);
        box->isHidden = false;
    });
    
    amplitude.activatePhysics();
    amplitude.isHidden = false;

    example1.activatePhysics();
    example1.isHidden = false;
    
    example2.activatePhysics();
    example2.isHidden = false;
    
    example3.activatePhysics();
    example3.isHidden = false;
    
    example4.activatePhysics();
    example4.isHidden = false;
}

void dioramaHUD::update (State state) {
    background.update(state);
    
    for (UIBox* box : items) {
        box->update(state);   
    }
    
    amplitude.update(state);
    example1.update(state);
    example2.update(state);
    example3.update(state);
    example4.update(state);
}
