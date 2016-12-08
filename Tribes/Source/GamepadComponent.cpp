/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GamepadComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/GamepadComponent.hpp"

float         * axes;
bool buttons[GAMEPAD_MAX] = {};

int connected = 0;

void callback (int joy, int event) {
    switch (event) {
        case GLFW_CONNECTED: connected = GLFW_TRUE;
        case GLFW_DISCONNECTED: connected = GLFW_FALSE;
    }
}

GamepadComponent::GamepadComponent (GLFWwindow* window, Game* game) {
    this->window = window;
    this->game = game;
    
    connected = glfwJoystickPresent(GLFW_JOYSTICK_1);
    
    glfwSetJoystickCallback(callback);
}

GamepadComponent::~GamepadComponent () {
    
}

void GamepadComponent::init() {
    
}

void GamepadComponent::update() {
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

bool GamepadComponent::isButtonDown (int button) {
   return buttons[button];
}

void GamepadComponent::buttonHandled (int button) {
    buttons[button] = false;
}

float GamepadComponent::getAxisState(int axis) {
    return axesStates[axis];
}

void GamepadComponent::logButtonPollData(int size, const unsigned char pollData[size]) {
    for (int i = 0; i < size; i++) {
        lastButtonPollData[i] = pollData[i];
    }
}

void GamepadComponent::logAxesPollData(int size, const float pollData[size]) {
    for (int i = 0; i < size; i++) {
        axesStates[i] = pollData[i];
    }
}




