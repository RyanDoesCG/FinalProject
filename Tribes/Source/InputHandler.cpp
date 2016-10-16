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

#include "../Headers/Engine/MathsToolkit.hpp"

void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);
void keyCallback           (GLFWwindow* window, int key, int scancode, int action, int mods);

// Ugly global state to accomodate the callbacks
bool  activeKeys[KEYCOUNT] = {};
float mouseX;
float mouseY;

InputHandler::InputHandler(Game* g) {
    game = g;
    
    GLFWwindow* gameWindow = game->getWindowObject()->getWindow();
    
    // Capture and Hide Mouse
//  glfwSetInputMode         (gameWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    unsigned char pixels[4 * 4 * 4];
    memset(pixels, 0xff, sizeof(pixels));
    
    GLFWimage image;
    image.width = 4;
    image.height = 4;
    image.pixels = pixels;
    
    glfwSetCursor(gameWindow, glfwCreateCursor(&image, 0, 0));
    
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
    game->getHUD()->updateMousePosition(mouseX, mouseY);

    for (int i = 0; i < KEYCOUNT; i++) {
        if (activeKeys[i]) {
            switch(i) {
                case GLFW_KEY_W:
                    game->planet->grow();
                    break;
                case GLFW_KEY_A:
                    game->planet->rotateLeft();
                    game->backdrop->rotateRight();
                    break;
                case GLFW_KEY_S:
                    game->planet->shrink();
                    break;
                case GLFW_KEY_D:
                    game->planet->rotateRight();
                    game->backdrop->rotateLeft();
                    break;
                    
                /** 
                 *  the following keys are removed upon use
                 */
                case GLFW_KEY_SPACE:
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
    if (action == GLFW_PRESS) activeKeys[key] = true;
    else if (action == GLFW_RELEASE) activeKeys[key] = false;
}

void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos) {
    mouseX = xpos;
    mouseY = ypos;
}
