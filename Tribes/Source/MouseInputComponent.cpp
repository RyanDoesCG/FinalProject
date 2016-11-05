/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MouseInputComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/MouseInputComponent.hpp"

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
double mouseX;
double mouseY;

void mouseActionCallback   (GLFWwindow* window, int button, int action, int mods);
void mouseScrollCallback   (GLFWwindow* window, double xoffset, double yoffset);
void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);

MouseInputComponent::MouseInputComponent (GLFWwindow* window, Game* game) {
    this->window = window;
    this->game = game;
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    
    glfwSetCursorPosCallback   (window, mouseMovementCallback);
    glfwSetMouseButtonCallback (window, mouseActionCallback);
    glfwSetScrollCallback      (window, mouseScrollCallback);
}

MouseInputComponent::~MouseInputComponent () {

}

void MouseInputComponent::init () {

}

void MouseInputComponent::update() {
    glfwPollEvents();
    
    std::cout << "x: " << mouseX << "\ty: " << mouseY << "\n";
    
    for (int i = 0; i < MOUSE_EVENTS_MAX; i++) {
        if (mouseEvents[i]) {
            switch(i) {
                case MOUSE_CLICK_LEFT:
                    std::cout << "mouse left" << std::endl;
                    break;
                case MOUSE_CLICK_RIGHT:
                    std::cout << "mouse right" << std::endl;
                    break;
                case MOUSE_SCROLL_LEFT:
                    break;
                case MOUSE_SCROLL_RIGHT:
                    break;
                case MOUSE_SCROLL_UP:
                    break;
                case MOUSE_SCROLL_DOWN:
                    break;
            }
        }
    }
}

void mouseActionCallback (GLFWwindow* window, int button, int action, int mods) {
    mouseEvents[button] = action;
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
    mouseX = xpos;
    mouseY = ypos;
}
