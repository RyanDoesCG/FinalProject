//
//  InputManager.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "InputManager.hpp"

Gamepad  InputManager::gamepad  = Gamepad  ();
Keyboard InputManager::keyboard = Keyboard ();
Mouse    InputManager::mouse    = Mouse    ();

Gamepad*    InputManager::getGamepadHandle  () { return &gamepad; }
Keyboard*   InputManager::getKeyboardHandle () { return &keyboard; }
Mouse*      InputManager::getMouseHandle    () { return &mouse; }

void InputManager::initialise (GLFWwindow* window) {
    gamepad   .attach ();
    keyboard  .attach (window);
    mouse     .attach (window);
}

void InputManager::update () {
    glfwPollEvents();
    gamepad   .update ();
    keyboard  .update ();
    mouse     .update ();
}
