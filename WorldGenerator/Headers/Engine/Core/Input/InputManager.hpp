//
//  InputManager.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include "glfw3.h"

#include "Gamepad.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

#include <vector>

class InputManager {
public:
    static Gamepad*    getGamepadHandle  ();
    static Keyboard*   getKeyboardHandle ();
    static Mouse*      getMouseHandle    ();
    
    static void initialise (GLFWwindow* window);
    
    static void update ();
    
private:
    static Gamepad  gamepad;
    static Keyboard keyboard;
    static Mouse    mouse;
    
};

#endif /* InputManager_hpp */
