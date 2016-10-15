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
                    game->planet->grow();
                    break;
                case GLFW_KEY_A:
                    game->planet->rotateLeft();
                    break;
                case GLFW_KEY_S:
                    game->planet->shrink();
                    break;
                case GLFW_KEY_D:
                    game->planet->rotateRight();
                    break;
                    
                /** 
                 *  the following keys are removed upon use
                 */
                case GLFW_KEY_SPACE:
                    game->getWindowObject()->randomiseClearColour();
                    activeKeys[GLFW_KEY_SPACE] = false;
                    break;
                case GLFW_KEY_ESCAPE:
                    activeKeys[GLFW_KEY_ESCAPE] = false;
                    game->pause();
                    break;
            }
        }
    }
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    if (action == GLFW_PRESS)
        activeKeys[key] = true;

    else if (action == GLFW_RELEASE)
        activeKeys[key] = false;
}

void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos) {
//    std::cout << "x: " << xpos << std::endl;
//    std::cout << "y: " << ypos << std::endl;
}
