//
//  Menu.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu (GraphicsEngine* graph, PhysicsEngine* phys):
    dioramas (graph, phys),
    planets  (graph, phys),
    quit     (graph, phys) {
        
    // dioarama generator
    items.push_back(&dioramas);
    items.at(0)->scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(0)->moveTo(glm::vec3(0.0, -0.35, 0.0));
    items.at(0)->update(MENU);
    
    // planet generator
    items.push_back(&planets);
    items.at(1)->scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(1)->moveTo(glm::vec3(0.0, -0.7, 0.0));
    items.at(1)->update(MENU);

    // quit
    items.push_back(&quit);
    items.at(2)->scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(2)->moveTo(glm::vec3(0.0, -1.05, 0.0));
    items.at(2)->update(MENU);
        
    engine = graph;
}

Menu::~Menu () {
    
}

void Menu::hide () {
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        //box->setAlpha(0);
        box->isHidden = true;
    });
}

void Menu::show () {
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        //box->setAlpha(1);
        box->isHidden = false;
    });
}

void Menu::update (State state) {
    if (items.front()->isHidden == false ) {
        engine->addToText("diorama generator", glm::vec2(0,  -120), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("planet generator",  glm::vec2(0, -230), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("exit",              glm::vec2(0, -350), 0.24, glm::vec3(0.64, 0.64, 0.64));
    }
    
    for (UIBox* box : items)
        box->update(state);
}
