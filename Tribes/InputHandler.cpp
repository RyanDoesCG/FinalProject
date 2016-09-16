/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.cpp
 *  Tribes
 *
 *  Created by ryan needham on 03/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "InputHandler.hpp"
#include "Game.hpp"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos);

InputHandler::InputHandler(Game* g) {
    game = g;
    
    GLFWwindow* gameWindow = game->getWindowObject()->getWindow();
    
    // Capture and Hide Mouse
//  glfwSetInputMode         (gameWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // Build mouse image
    unsigned char pixels[16 * 16 * 4];
    memset(pixels, 0xcc, sizeof(pixels));
    GLFWimage image;
    image.width  = 16;
    image.height = 16;
    image.pixels = pixels;
    GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
    if (!cursor) std::cout << "Cursor Creation Failed" << std::endl;
    
    // Set Callbacks
    glfwSetCursorPosCallback (gameWindow, mouseMovementCallback);
    glfwSetKeyCallback       (gameWindow, keyCallback);
    glfwSetCursor            (gameWindow, cursor);
}

InputHandler::~InputHandler () {

}

void InputHandler::checkInput() {
    glfwPollEvents();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch(key) {
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
        }
    }
}

void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos) {
//    std::cout << "x: " << xpos << std::endl;
//    std::cout << "y: " << ypos << std::endl;
}
