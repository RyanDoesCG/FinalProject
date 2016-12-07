/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardCopmonent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/KeyboardComponent.hpp"

#define KEYCOUNT 348

bool activeKeys[KEYCOUNT] = {};

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    activeKeys[key] = action;
}

KeyboardCopmonent::KeyboardCopmonent (GLFWwindow* window, Game* game) {
    this->window = window;
    this->game = game;
    
    glfwSetKeyCallback (window, keyboardCallback);
}

KeyboardCopmonent::~KeyboardCopmonent () {
    
}

void KeyboardCopmonent::init () {

}

void KeyboardCopmonent::update () {
    glfwPollEvents();
}

bool KeyboardCopmonent::isKeyDown(int keycode) {
    if (activeKeys[keycode]) return true;
    else return false;
}

void KeyboardCopmonent::keyHandled(int keycode) {
    activeKeys[keycode] = false;
}
