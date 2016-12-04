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
    
    glfwSetKeyCallback (window, keyboardCallback);
}

KeyboardInputComponent::~KeyboardInputComponent () {
    
}

void KeyboardInputComponent::init () {

}

void KeyboardInputComponent::update () {
    glfwPollEvents();
}

bool KeyboardInputComponent::isKeyDown(int keycode) {
    if (activeKeys[keycode]) return true;
    else return false;
}

void KeyboardInputComponent::keyHandled(int keycode) {
    activeKeys[keycode] = false;
}
