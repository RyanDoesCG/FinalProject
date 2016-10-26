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

#define MOUSE_CLICK_LEFT        0
#define MOUSE_CLICK_RIGHT       1
#define MOUSE_SCROLL_LEFT       2
#define MOUSE_SCROLL_RIGHT      3
#define MOUSE_SCROLL_UP         4
#define MOUSE_SCROLL_DOWN       5
#define MOUSE_MAX               6

#define GAMEPAD_BUTTON_A        0
#define GAMEPAD_BUTTON_B        1
#define GAMEPAD_BUTTON_X        2
#define GAMEPAD_BUTTON_y        3
#define GAMEPAD_TRIGGER_LEFT    4
#define GAMEPAD_TRIGGER_RIGHT   5
#define GAMEPAD_BUMPER_LEFT     6
#define GAMEPAD_BUMPER_RIGHT    7
#define GAMEPAD_STICK_RIGHT     8
#define GAMEPAD_STICK_LEFT      9
#define GAMEPAD_DPAD_UP         10
#define GAMEPAD_DPAD_DOWN       11
#define GAMEPAD_DPAD_LEFT       12
#define GAMEPAD_DPAD_RIGHT      13
#define GAMEPAD_SPECIAL_START   14
#define GAMEPAD_SPECIAL_SELECT  15
#define GAMEPAD_SPECIAL_HOME    16
#define GAMEPAD_MAX             17

// a C style solution for a C API
bool activeKeys  [KEYCOUNT]  = {};
bool mouseEvents [MOUSE_MAX] = {};

/**
 * FIND A GAMEPAD AND TEST
 * NOTE: GLFW_PRESS = 1, GLFW_RELEASE = 0
 */
const float         * gamepadAxis;    int axisCount;
const unsigned char * gamepadButtons; int buttonCount;

float mouseX;
float mouseY;

// On-action callbacks
void mouseMovementCallback (GLFWwindow* window, double xpos,    double ypos);
void mouseActionCallback   (GLFWwindow* window, int    button,     int action,   int mods);
void mouseScrollCallback   (GLFWwindow* window, double xoffset, double yoffset);
void keyboardCallback      (GLFWwindow* window, int    key,        int scancode, int action, int mods);
void gamepadCallback       (int gamepadID,      int    event); // NEEDS TESTING

InputHandler::InputHandler(Game* g) {
    game = g;
    
    GLFWwindow* gameWindow = game->getWindow();
    
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
    populateInputArray (); // do C style stuff
    processInputArray  (); // process and manipulate C++ classes
}

void InputHandler::populateInputArray() { glfwPollEvents(); }
void InputHandler::processInputArray() {
    game->getHUD()->updateMousePosition(mouseX, mouseY);
    
    /** 
     *  note: macOS flips scroll up and scroll down
     *  with natural scrolling
     */
    
    // MOUSE/TRACKPAD
    for (int i = 0; i < MOUSE_MAX; i++) {
        if (mouseEvents[i]) {
            switch(i) {
                // continuous
                case MOUSE_CLICK_LEFT:
                    std::cout << "LEFT CLICK" << std::endl;
                    break;
                case MOUSE_CLICK_RIGHT:
                    std::cout << "RIGHT CLICK" << std::endl;
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
                    
                // continuous
                case GLFW_KEY_W:
                    game->planet->grow();
                    game->backdrop->grow();
                    break;
                case GLFW_KEY_A:
                    game->planet->rotateLeft();
                    //game->backdrop->rotateRight();
                    break;
                case GLFW_KEY_S:
                    game->planet->shrink();
                    game->backdrop->shrink();
                    break;
                case GLFW_KEY_D:
                    game->planet->rotateRight();
                    //game->backdrop->rotateLeft();
                    break;
                case GLFW_KEY_Q:
                    game->end();
                    break;
                    
                // Single fire
                case GLFW_KEY_R:
                    game->planet->randomise();
                    activeKeys[i] = false;
                    break;
                case GLFW_KEY_SPACE:
                    activeKeys[i] = false;
                    break;
                case GLFW_KEY_ESCAPE:
                    game->pause();
                    activeKeys[i] = false;
                    break;
            }
        }
    }
    
    // GAMEPAD AXES
    for (int i = 0; i < axisCount; i++) {
        std::cout << gamepadAxis[i] << std::endl;
    }
    
    // GAMEPAD BUTTONS
    for (int i = 0; i < buttonCount; i++) {
        if (gamepadButtons[i]) {
            switch (i) {
                case GAMEPAD_BUTTON_A:
                    std::cout << "gamepad a" << std::endl;
                    break;
                case GAMEPAD_BUTTON_B:
                    std::cout << "gamepad b" << std::endl;
                    break;
                case GAMEPAD_BUTTON_X:
                    std::cout << "gamepad x" << std::endl;
                    break;
                case GAMEPAD_BUTTON_y:
                    std::cout << "gamepad y" << std::endl;
                    break;
                case GAMEPAD_TRIGGER_LEFT:
                    std::cout << "gamepad left trig" << std::endl;
                    game->planet->shrink();
                    game->backdrop->shrink();
                    break;
                case GAMEPAD_TRIGGER_RIGHT:
                    std::cout << "gamepad right trig" << std::endl;
                    game->planet->grow();
                    game->backdrop->grow();
                    break;
                case GAMEPAD_BUMPER_LEFT:
                    std::cout << "gamepad left bumper" << std::endl;
                    break;
                case GAMEPAD_BUMPER_RIGHT:
                    std::cout << "gamepad right bumper" << std::endl;
                    break;
                case GAMEPAD_STICK_LEFT:
                    std::cout << "gamepad L3" << std::endl;
                    break;
                case GAMEPAD_STICK_RIGHT:
                    std::cout << "gamepad R3" << std::endl;
                    break;
                case GAMEPAD_DPAD_UP:
                    std::cout << "gamepad up" << std::endl;
                    break;
                case GAMEPAD_DPAD_DOWN:
                    std::cout << "gamepad down" << std::endl;
                    break;
                case GAMEPAD_DPAD_LEFT:
                    std::cout << "gamepad left" << std::endl;
                    break;
                case GAMEPAD_DPAD_RIGHT:
                    std::cout << "gamepad right" << std::endl;
                    break;
                case GAMEPAD_SPECIAL_START:
                    std::cout << "gamepad start" << std::endl;
                    break;
                case GAMEPAD_SPECIAL_SELECT:
                    std::cout << "gamepad select" << std::endl;
                    break;
                case GAMEPAD_SPECIAL_HOME:
                    std::cout << "gamepad home" << std::endl;
                    break;
            }
        }
    }
}

void keyboardCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    activeKeys[key] = action;
}

void mouseMovementCallback (GLFWwindow* window, double xpos, double ypos) {
    mouseX = xpos;
    mouseY = ypos;
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

/** 
 * FIND A GAMEPAD AND TEST
 */
void gamepadCallback (int gamepadID, int event) {
    gamepadAxis    = glfwGetJoystickAxes    (gamepadID, &axisCount);
    gamepadButtons = glfwGetJoystickButtons (gamepadID, &buttonCount);
    std::cout << "Gamepad Event Recieved" << std::endl;
    
    if      (event == GLFW_CONNECTED)    std::cout << "Gamepad Connected";
    else if (event == GLFW_DISCONNECTED) std::cout << "Gamepad Disconnected";
}
