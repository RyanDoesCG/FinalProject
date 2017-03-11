//
//  Menu.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu (GraphicsEngine* graph, PhysicsEngine* phys) {
    // dioarama generator
    items.push_back(UIBox(graph, phys));
    items.at(0).scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(0).moveTo(glm::vec3(0.0, 0.0, 0.0));
    items.at(0).update();
    
    // planet generator
    items.push_back(UIBox(graph, phys));
    items.at(1).scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(1).moveTo(glm::vec3(0.0, -0.25, 0.0));
    items.at(1).update();
    
    // options
    items.push_back(UIBox(graph, phys));
    items.at(2).scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(2).moveTo(glm::vec3(0.0, -0.5, 0.0));
    items.at(2).update();

    // quit
    items.push_back(UIBox(graph, phys));
    items.at(3).scaleTo(glm::vec3(1.5, 0.15, 0));
    items.at(3).moveTo(glm::vec3(0.0, -0.75, 0.0));
    items.at(3).update();
}

Menu::~Menu () {
    
}

void Menu::update () {
    for_each(items.begin(), items.end(), [](UIBox box) {
        box.update();
    });
}
