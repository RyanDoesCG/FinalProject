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
bool firstEvent = true;

double  lastX   = 0;
double  lastY   = 0;
double  mouseX  = 0;
double  mouseY  = 0;
GLfloat xoffset = 0;
GLfloat yoffset = 0;

void mouseActionCallback   (GLFWwindow* window, int button, int action, int mods);
void mouseScrollCallback   (GLFWwindow* window, double xoffset, double yoffset);
void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);

MouseInputComponent::MouseInputComponent (GLFWwindow* window, Game* game) {
    this->window = window;
    this->game = game;
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    unsigned char pixels[4 * 4 * 4];
    memset(pixels, 0xfa, sizeof(pixels));
    GLFWimage image;
    image.width = 4;
    image.height = 4;
    image.pixels = pixels;
    GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
    
    glfwSetCursor(window, cursor);
    glfwSetCursorPos(window, 0, 0);

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
    
    for (int i = 0; i < MOUSE_EVENTS_MAX; i++) {
        if (mouseEvents[i]) {
            switch(i) {
                case MOUSE_CLICK_LEFT:
                    std::cout << "mouse left" << std::endl;
                    std::cout << "x: " << mouseX << "\ty: " << mouseY << std::endl;
                    break;
                case MOUSE_CLICK_RIGHT:
                    std::cout << "mouse right" << std::endl;
                    std::cout << "x: " << mouseX << "\ty: " << mouseY << std::endl;
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

float MouseInputComponent::getMouseX  () { return mouseX; }
float MouseInputComponent::getMouseY  () { return mouseY; }
float MouseInputComponent::getXoffset () { return xoffset; }
float MouseInputComponent::getYoffset () { return yoffset; }

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

    GLfloat sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
}
