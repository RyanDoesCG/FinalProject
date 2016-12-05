//
//  Moon.cpp
//  Tribes
//
//  Created by Ryan Needham on 04/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Moon.hpp"
#include "../Headers/GLFW/glfw3.h"

Moon::Moon () : Model("sphere/sphere") {
    setPosition(glm::vec3(-1, 0.4, 0.0));
    setColour(glm::vec3(0.175, 0.175, 0.175));
    setShader("Moon", BASIC);
    setScale(0.1);
}

Moon::~Moon () {
    
}

void Moon::update(GameState state, SceneCamera *camera) {
    switch (state) {
        case MAIN_MENU: {
            GLfloat radius = 2;
            position.x = (sin(glfwGetTime()/24) * radius) + 1;
            position.z = (cos(glfwGetTime()/24) * radius) + 1;
            
            break;
        }
        case RUNNING_FREEMODE: {
            GLfloat radius = 2;
            position.x = sin(glfwGetTime()/24) * radius;
            position.z = cos(glfwGetTime()/24) * radius;
            
            break;
        }
        case RUNNING_EDITMODE: {
            GLfloat radius = 2;
            position.x = sin(glfwGetTime()/24) * radius;
            position.z = cos(glfwGetTime()/24) * radius;
            
            setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            
            break;
        }
    }
    
    shader->update();
    Model::update(state, camera);
}
