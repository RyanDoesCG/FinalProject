//
//  Moon.cpp
//  Tribes
//
//  Created by Ryan Needham on 04/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Moon.hpp"
#include "../Headers/Engine/ColourPalette.hpp"
#include "../Headers/GLFW/glfw3.h"

Moon::Moon () : Model("sphere/sphere") {
    setPosition(glm::vec3(-1, 0.4, 0.0));
    setColour(ColourPalette::getColour(DarkGray));
    setShader("Moon", BASIC);
    setScale(0.1);
    
    speed = 24;
}

Moon::~Moon () {
    
}

void Moon::setSpeed(int s) {
    if (s != 0) {
        speed = s;
    }
}

void Moon::update(GameState state, SceneCamera *camera) {
    switch (state) {
        case MAIN_MENU: case RUNNING_FREEMODE: case RUNNING_EDITMODE: {
            GLfloat radius = 2;
            position.x = (sin(glfwGetTime()/speed) * radius);
            position.z = (cos(glfwGetTime()/speed) * radius);
            
            break;
        }
    }
    
    shader->update();
    Model::update(state, camera);
}
