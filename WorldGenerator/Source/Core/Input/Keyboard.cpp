//
//  Keyboard.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Keyboard.hpp"

#define KEYCOUNT 348

bool activeKeys[KEYCOUNT] = {};

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    activeKeys[key] = action;
}

Keyboard::Keyboard () {
    
}

Keyboard::~Keyboard () {
    
}

void Keyboard::attach(GLFWwindow *window) {
    glfwSetKeyCallback (window, keyboardCallback);
}

void Keyboard::update () {
    glfwPollEvents();
}

bool Keyboard::isKeyDown(int keycode) {
    if (activeKeys[keycode]) return true;
    else return false;
}

void Keyboard::keyHandled(int keycode) {
    activeKeys[keycode] = false;
}
