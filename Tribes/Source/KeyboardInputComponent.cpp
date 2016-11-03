/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardInputComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/KeyboardInputComponent.hpp"

#define KEYCOUNT 348

bool activeKeys[KEYCOUNT] = {};

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    activeKeys[key] = action;
}

KeyboardInputComponent::KeyboardInputComponent (GLFWwindow* window, Game* game) {
    this->window = window;
    this->game = game;
    
    init();
}

KeyboardInputComponent::~KeyboardInputComponent () {
    
}

void KeyboardInputComponent::init () {
    glfwSetKeyCallback (window, keyboardCallback);
}

void KeyboardInputComponent::update() {
    glfwPollEvents();
    
    for (int i = 0; i < KEYCOUNT; i++) {
        if (activeKeys[i]) {
            switch(i) {
                case GLFW_KEY_W:
                    break;
                case GLFW_KEY_A:
                    break;
                case GLFW_KEY_S:
                    break;
                case GLFW_KEY_D:
                    break;
                case GLFW_KEY_Q:
                    game->end();
                    break;
                case GLFW_KEY_R:
                    break;
                case GLFW_KEY_SPACE:
                    break;
                case GLFW_KEY_ESCAPE:
                    break;
            }
        }
    }
}
