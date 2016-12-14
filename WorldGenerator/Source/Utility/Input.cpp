/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Input.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 14/12/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Utility/Input.hpp"

GamepadComponent Input::gamepad   = GamepadComponent();
KeyboardComponent Input::keyboard = KeyboardComponent();
MouseComponent Input::mouse       = MouseComponent();


GamepadComponent*    Input::getGamepadHandle  () {return &gamepad;}
KeyboardComponent*   Input::getKeyboardHandle () {return &keyboard;}
MouseComponent*      Input::getMouseHandle    () {return &mouse;}
    
void Input::initialise (GLFWwindow* window) {
    gamepad.attach();
    keyboard.attach(window);
    mouse.attach(window);
}
    
void Input::update () {
    gamepad.update();
    keyboard.update();
    mouse.update();
}
