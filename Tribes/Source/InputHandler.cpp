/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.cpp
 *  Tribes
 *
 *  Created by ryan needham on 03/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/InputHandler.hpp"
#include "../Headers/Engine/Game.hpp"

void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);
void keyCallback           (GLFWwindow* window, int key, int scancode, int action, int mods);

/// URRRRGGGHHHHH NO DONT DO THIS
bool activeKeys[KEYCOUNT] = {};

InputHandler::InputHandler(Game* g) {
    game = g;
    
    GLFWwindow* gameWindow = game->getWindowObject()->getWindow();
    
    // Capture and Hide Mouse
//  glfwSetInputMode         (gameWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    
    // Set Callbacks
    glfwSetCursorPosCallback (gameWindow, mouseMovementCallback);
    glfwSetKeyCallback       (gameWindow, keyCallback);
}

InputHandler::~InputHandler () {

}

void InputHandler::update() {
    checkInput();
    processInput();
}

void InputHandler::checkInput() { glfwPollEvents(); }
void InputHandler::processInput() {
    for (int i = 0; i < KEYCOUNT; i++) {
        if (activeKeys[i]) {
            switch(i) {
                case GLFW_KEY_W:
                    std::cout << "w pressed\n";
                    break;
                case GLFW_KEY_A:
                    std::cout << "a pressed\n";
                    break;
                case GLFW_KEY_S:
                    std::cout << "s pressed\n";
                    break;
                case GLFW_KEY_D:
                    std::cout << "d pressed\n";
                    break;
                case GLFW_KEY_ESCAPE:
                    // pause key needs to be removed
                    activeKeys[GLFW_KEY_ESCAPE] = false;
                    game->pause();
                    break;
            }
        }
    }
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    /** 
     *  if a key is pressed, add it
     */
    if (action == GLFW_PRESS) {
        switch(key) {
            case GLFW_KEY_W:
                activeKeys[GLFW_KEY_W] = true;
                break;
            case GLFW_KEY_A:
                activeKeys[GLFW_KEY_A] = true;
                break;
            case GLFW_KEY_S:
                activeKeys[GLFW_KEY_S] = true;
                break;
            case GLFW_KEY_D:
                activeKeys[GLFW_KEY_D] = true;
                break;
            case GLFW_KEY_ESCAPE:
                activeKeys[GLFW_KEY_ESCAPE] = true;
                break;
        }
    }
    
    /** 
     *  if a key is released, remove it
     */
    else if (action == GLFW_RELEASE) {
        switch(key) {
            case GLFW_KEY_W:
                activeKeys[GLFW_KEY_W] = false;
                break;
            case GLFW_KEY_A:
                activeKeys[GLFW_KEY_A] = false;
                break;
            case GLFW_KEY_S:
                activeKeys[GLFW_KEY_S] = false;
                break;
            case GLFW_KEY_D:
                activeKeys[GLFW_KEY_D] = false;
                break;
            case GLFW_KEY_ESCAPE:
                activeKeys[GLFW_KEY_ESCAPE] = false;
                break;
        }
    }
}

void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos) {
//    std::cout << "x: " << xpos << std::endl;
//    std::cout << "y: " << ypos << std::endl;
}
