//
//  Gamepad.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Gamepad.hpp"

float         * axes;
bool buttons[GAMEPAD_MAX] = {};

int connected = 0;

void callback (int joy, int event) {
    switch (event) {
        case GLFW_CONNECTED: connected = GLFW_TRUE;
        case GLFW_DISCONNECTED: connected = GLFW_FALSE;
    }
}

Gamepad::Gamepad () {
    
}

Gamepad::~Gamepad () {
    
}

void Gamepad::attach() {
    connected = glfwJoystickPresent(GLFW_JOYSTICK_1);
    
    glfwSetJoystickCallback(callback);
}

void Gamepad::update() {
    if (connected == GLFW_TRUE) {
        // BUTTONS
        // poll
        int buttonPollDataLength;
        const unsigned char* buttonPollData = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonPollDataLength);
        // populate array
        for (int i = 0; i < buttonPollDataLength; i++) {
            if (buttonPollData[i] == GLFW_PRESS &&
                buttonPollData[i] != lastButtonPollData[i]) {
                buttons[i] = true;
            }
            
            if (buttonPollData[i] == GLFW_RELEASE) {
                buttons[i] = false;
            }
        }
        // store for next time
        logButtonPollData(buttonPollDataLength, buttonPollData);
        
        // AXES
        // poll
        int axesPollDataLength;
        const float* axesPollData = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesPollDataLength);
        // populate array
        logAxesPollData(axesPollDataLength, axesPollData);
    }
}

bool Gamepad::isButtonDown (int button) {
    return buttons[button];
}

void Gamepad::buttonHandled (int button) {
    buttons[button] = false;
}

float Gamepad::getAxisState(int axis) {
    return axesStates[axis];
}

void Gamepad::resetAxisState(int axis) {
    axesStates[axis] = 0;
}

void Gamepad::logButtonPollData(int size, const unsigned char pollData[size]) {
    for (int i = 0; i < size; i++) {
        lastButtonPollData[i] = pollData[i];
    }
}

void Gamepad::logAxesPollData(int size, const float pollData[size]) {
    for (int i = 0; i < size; i++) {
        axesStates[i] = pollData[i];
    }
}

