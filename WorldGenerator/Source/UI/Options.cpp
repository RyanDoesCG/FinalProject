//
//  Options.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Options.hpp"

Options::Options (GraphicsEngine* graph, PhysicsEngine* phys):
    resolution (graph, phys),
    sound      (graph, phys),
    about      (graph, phys),
    back       (graph, phys) {
    
    // resolution
    items.push_back(&resolution);
    items.at(0)->scaleTo(glm::vec3(2, 0.15, 0));
    items.at(0)->moveTo(glm::vec3(0.0, -0.17, -10));
    items.at(0)->update();
    
    // sound
    items.push_back(&sound);
    items.at(1)->scaleTo(glm::vec3(2, 0.15, 0));
    items.at(1)->moveTo(glm::vec3(0.0, -0.525, -10));
    items.at(1)->update();
    
    // about
    items.push_back(&about);
    items.at(2)->scaleTo(glm::vec3(2, 0.15, 0));
    items.at(2)->moveTo(glm::vec3(0.0, -0.865, -10));
    items.at(2)->update();
    
    // back
    items.push_back(&back);
    items.at(3)->scaleTo(glm::vec3(1, 0.15, 0));
    items.at(3)->moveTo(glm::vec3(0.0, -1.25, 10));
    items.at(3)->update();
}

Options::~Options () {}

void Options::hide () {
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        box->setAlpha (0);
    });
}

void Options::show () {
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        box->setAlpha (1);
    });
}

void Options::update () {
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->update();
    });
}
