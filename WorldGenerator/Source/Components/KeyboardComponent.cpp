/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Components/KeyboardComponent.hpp"

#define KEYCOUNT 348

bool activeKeys[KEYCOUNT] = {};

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    activeKeys[key] = action;
}

KeyboardComponent::KeyboardComponent () {

}

KeyboardComponent::~KeyboardComponent () {
    
}

void KeyboardComponent::attach(GLFWwindow *window) {
    glfwSetKeyCallback (window, keyboardCallback);
}

void KeyboardComponent::init () {

}

void KeyboardComponent::update () {
    glfwPollEvents();
}

bool KeyboardComponent::isKeyDown(int keycode) {
    if (activeKeys[keycode]) return true;
    else return false;
}

void KeyboardComponent::keyHandled(int keycode) {
    activeKeys[keycode] = false;
}
