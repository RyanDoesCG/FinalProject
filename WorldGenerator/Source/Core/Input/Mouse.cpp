//
//  Mouse.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "glfw3.h"
#include "Mouse.hpp"

#include <iostream>

enum MouseEvent {
    MOUSE_CLICK_LEFT,
    MOUSE_CLICK_RIGHT,
    MOUSE_SCROLL_LEFT,
    MOUSE_SCROLL_RIGHT,
    MOUSE_SCROLL_UP,
    MOUSE_SCROLL_DOWN,
    MOUSE_EVENTS_MAX
};

bool mouseEvents[MOUSE_EVENTS_MAX] = {};
bool firstEvent = true;

double  lastX   = 0;
double  lastY   = 0;
double  mouseX  = 0;
double  mouseY  = 0;
GLfloat xoffset = 0;
GLfloat yoffset = 0;


bool leftButton = false;
bool rightButton = false;

GLfloat sensitivity = 0.005f;

void mouseActionCallback   (GLFWwindow* window, int button, int action, int mods);
void mouseScrollCallback   (GLFWwindow* window, double xoffset, double yoffset);
void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);

Mouse::Mouse () {
    
}

Mouse::~Mouse () {
    
}

void Mouse::attach(GLFWwindow *window) {
    glfwSetCursorPosCallback   (window, mouseMovementCallback);
    glfwSetMouseButtonCallback (window, mouseActionCallback);
    glfwSetScrollCallback      (window, mouseScrollCallback);
    
    this->window = window;
}


void Mouse::update() {
    glfwPollEvents();
}

void Mouse::hide () {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Mouse::show () {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Mouse::place (int x, int y) {
    glfwSetCursorPos(window, x, y);
}

float Mouse::getMouseX  () { return mouseX; }
float Mouse::getMouseY  () { return mouseY; }
float Mouse::getXoffset () { return xoffset; }
float Mouse::getYoffset () { return yoffset; }

bool Mouse::leftButtonDown  () { return leftButton; }
bool Mouse::rightButtonDown () { return rightButton; }

void Mouse::leftButtonHandled  () {leftButton = false; }
void Mouse::rightButtonHandled () {rightButton = false; }

void mouseActionCallback (GLFWwindow* window, int button, int action, int mods) {
    mouseEvents[button] = action;
    
    leftButton  = (button == GLFW_MOUSE_BUTTON_1) && (action == GLFW_PRESS);
    rightButton = (button == GLFW_MOUSE_BUTTON_2) && (action == GLFW_PRESS);
}

void mouseScrollCallback (GLFWwindow* window, double xoffset, double yoffset) {
    
    // remove signing so both values are positive
    unsigned int xNormalised = xoffset;
    unsigned int yNormalised = yoffset;
    
    // act upon the dominant value
    if (xNormalised > yNormalised) {
        if      (xoffset > 0) mouseEvents[MOUSE_SCROLL_LEFT]  = true;
        else if (xoffset < 0) mouseEvents[MOUSE_SCROLL_RIGHT] = true;
    }
    
    if (yNormalised > xNormalised) {
        if      (yoffset > 0) mouseEvents[MOUSE_SCROLL_UP] = true;
        else if (yoffset < 0) mouseEvents[MOUSE_SCROLL_DOWN] = true;
    }
}

void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos) {
    
    // fix openning jump
    if (firstEvent) {
        lastX = xpos;
        lastY = ypos;
        firstEvent = false;
    }
    
    xoffset = xpos - lastX;
    yoffset = lastY - ypos;
    
    lastX = xpos;
    lastY = ypos;
    
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
}
