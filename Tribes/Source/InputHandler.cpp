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

enum MouseEvent {
    MOUSE_SCROLL_LEFT,
    MOUSE_SCROLL_RIGHT,
    MOUSE_SCROLL_UP,
    MOUSE_SCROLL_DOWN,
    MOUSE_LEFT_CLICK,
    MOUSE_RIGHT_CLICK,
    EVENTCOUNT
};

// a C style solution for a C API
bool  activeKeys     [KEYCOUNT]   = {};
bool  mouseEvents    [EVENTCOUNT] = {};

const float         * gamepadAxis;      int axisCount;
const unsigned char * gamepadButtons;   int buttonCount;

float mouseX;
float mouseY;

// On-action callbacks
void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos);
void mouseActionCallback   (GLFWwindow* window, int button, int action, int mods);
void mouseScrollCallback   (GLFWwindow* window, double xoffset, double yoffset);
void keyboardCallback      (GLFWwindow* window, int key, int scancode, int action, int mods);
void gamepadCallback       (int gamepadID, int event); // NEEDS TESTING


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
    glfwSetCursorPosCallback   (gameWindow, mouseMovementCallback);
    glfwSetMouseButtonCallback (gameWindow, mouseActionCallback);
    glfwSetScrollCallback      (gameWindow, mouseScrollCallback);
    glfwSetKeyCallback         (gameWindow, keyboardCallback);
    glfwSetJoystickCallback    (gamepadCallback);
}

InputHandler::~InputHandler () {

}

void InputHandler::update() {
    populateInputArray();
    processInputArray();
}

void InputHandler::populateInputArray() { glfwPollEvents(); }
void InputHandler::processInputArray() {
    game->getHUD()->updateMousePosition(mouseX, mouseY);
    
    /** 
     *  note: macOS flips scroll up and scroll down
     *  with natural scrolling
     */
    
    // MOUSE/TRACKPAD
    for (int i = 0; i < EVENTCOUNT; i++) {
        if (mouseEvents[i]) {
            switch(i) {
                case MOUSE_LEFT_CLICK:
                    
                    break;
                case MOUSE_RIGHT_CLICK:
                    
                    break;
                    
                // single fire
                case MOUSE_SCROLL_LEFT:
                    game->planet->rotateRight();
                    mouseEvents[i] = false;
                    break;
                case MOUSE_SCROLL_RIGHT:
                    game->planet->rotateLeft();
                    mouseEvents[i] = false;
                    break;
                case MOUSE_SCROLL_UP:
                    game->planet->shrink();
                    game->backdrop->shrink();
                    mouseEvents[i] = false;
                    break;
                case MOUSE_SCROLL_DOWN:
                    game->planet->grow();
                    game->backdrop->grow();
                    mouseEvents[i] = false;
                    break;
            }
        }
    }

    // KEYBOARD
    for (int i = 0; i < KEYCOUNT; i++) {
        if (activeKeys[i]) {
            switch(i) {
                case GLFW_KEY_W:
                    game->planet->grow();
                    game->backdrop->grow();
                    break;
                case GLFW_KEY_A:
                    game->planet->rotateLeft();
                    game->backdrop->rotateRight();
                    break;
                case GLFW_KEY_S:
                    game->planet->shrink();
                    game->backdrop->shrink();
                    break;
                case GLFW_KEY_D:
                    game->planet->rotateRight();
                    game->backdrop->rotateLeft();
                    break;
                case GLFW_KEY_Q:
                    game->end();
                    break;
                    
                // Single fire stuff
                case GLFW_KEY_R:
                    game->planet->randomise();
                    activeKeys[GLFW_KEY_R] = false;
                    break;
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
    
    // JOYSTICK/GAMEPAD
    for (int i = 0; i < axisCount; i++) {
        
    }
    
    for (int i = 0; i < buttonCount; i++) {
        switch (gamepadButtons[i]) {
            
        }
    }
}

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if      (action == GLFW_PRESS)   activeKeys[key] = true;
    else if (action == GLFW_RELEASE) activeKeys[key] = false;
}

void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos) {
    mouseX = xpos;
    mouseY = ypos;
}

void mouseActionCallback (GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            mouseEvents[MOUSE_RIGHT_CLICK] = true;
        }
    
        else if (button == GLFW_MOUSE_BUTTON_LEFT) {
            mouseEvents[MOUSE_LEFT_CLICK] = true;
        }
    }
    
    else if (action == GLFW_RELEASE) {
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            mouseEvents[MOUSE_RIGHT_CLICK] = false;
        }
        
        else if (button == GLFW_MOUSE_BUTTON_LEFT) {
            mouseEvents[MOUSE_LEFT_CLICK] = false;
        }
    }
}

void mouseScrollCallback (GLFWwindow* window, double xoffset, double yoffset) {
    
    // Figure out if the user means to swipe
    // up or left
    unsigned int xNormalised = xoffset;
    unsigned int yNormalised = yoffset;

    if (xNormalised > yNormalised) {
        if (xoffset > 0) {
            mouseEvents[MOUSE_SCROLL_LEFT] = true;
        }
    
        else if (xoffset < 0) {
            mouseEvents[MOUSE_SCROLL_RIGHT] = true;
        }
    }
    
    if (yNormalised > xNormalised) {
        if (yoffset > 0) {
            mouseEvents[MOUSE_SCROLL_UP] = true;
        }
        
        else if (yoffset < 0) {
            mouseEvents[MOUSE_SCROLL_DOWN] = true;
        }
    }
}

void gamepadCallback (int gamepadID, int event) {
    gamepadAxis    = glfwGetJoystickAxes(gamepadID, &axisCount);
    gamepadButtons = glfwGetJoystickButtons(gamepadID, &buttonCount);
    std::cout << "Gamepad Event Recieved" << std::endl;
}
