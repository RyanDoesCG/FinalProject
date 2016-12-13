/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GamepadComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 06/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GamepadComponent_hpp
#define GamepadComponent_hpp

#include "Component.hpp"
#include "../Core/Game.hpp"

// BUTTONS
#define GAMEPAD_DPAD_UP         0
#define GAMEPAD_DPAD_DOWN       1
#define GAMEPAD_DPAD_LEFT       2
#define GAMEPAD_DPAD_RIGHT      3
#define GAMEPAD_SPECIAL_START   4
#define GAMEPAD_SPECIAL_BACK    5
#define GAMEPAD_STICK_LEFT      6
#define GAMEPAD_STICK_RIGHT     7
#define GAMEPAD_LEFT_BUMPER     8
#define GAMEPAD_RIGHT_BUMPER    9
#define GAMEPAD_SPECIAL_HOME    10
#define GAMEPAD_BUTTON_A        11
#define GAMEPAD_BUTTON_B        12
#define GAMEPAD_BUTTON_X        13
#define GAMEPAD_BUTTON_Y        14
#define GAMEPAD_MAX             15

// AXES
#define LEFT_STICK_X_AXIS       0
#define LEFT_STICK_Y_AXIS       1
#define RIGHT_STICK_X_AXIS      2
#define RIGHT_STICK_Y_AXIS      3
#define LEFT_TRIGGER            4
#define RIGHT_TRIGGER           5

class GamepadComponent : public Component {
    public:
        GamepadComponent (GLFWwindow* window, Game* game);
       ~GamepadComponent ();
    
        virtual void init () override;
        virtual void update () override;
    
        bool isButtonDown (int button);
        void buttonHandled (int button);
    
        float getAxisState (int axis);
    
    private:
        GLFWwindow* window;
        Game* game;
    
        // storing button states
        void logButtonPollData(int size, const unsigned char pollData[size]);
        unsigned char lastButtonPollData[GAMEPAD_MAX] = {};
    
        // storing axes states
        void logAxesPollData(int size, const float pollDatap[size]);
        float axesStates[10] = {};
};

#endif /* GamepadComponent.hpp */
