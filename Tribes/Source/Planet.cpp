//
//  Planet.cpp
//  Tribes
//
//  Created by user on 30/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Planet.hpp"

Planet::Planet (): frame("sphere/sphere") {
    addChild(&frame);
    
    setColour(glm::vec3(1.0, 0.5, 0.5));
}

Planet::~Planet () {
    
}

void Planet::update(GameState state, SceneCamera *camera) {
    
    switch (state) {
        case MAIN_MENU:
            frame.setRotation(glm::vec3(0.0, frame.getRotation().y + 0.001, 0.0));
            frame.setPosition(glm::vec3(1.0, 0.0, 0.0));
            break;
        case RUNNING:
            frame.setRotation(glm::vec3(0.0, frame.getRotation().y + 0.001, 0.0));
            frame.setPosition(glm::vec3(0.0, 0.0, 0.0));
            break;
    }
    
    Actor::update(state, camera);
}
