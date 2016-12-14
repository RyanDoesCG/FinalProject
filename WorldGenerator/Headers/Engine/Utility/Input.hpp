/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Input.hpp
 *  Tribes
 *
 *  Created by ryan needham on 19/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Input_hpp
#define Input_hpp

#include "../Components/GamepadComponent.hpp"
#include "../Components/KeyboardComponent.hpp"
#include "../Components/MouseComponent.hpp"

#include <vector>

class Input {
    public:
        static GamepadComponent*    getGamepadHandle  ();
        static KeyboardComponent*   getKeyboardHandle ();
        static MouseComponent*      getMouseHandle    ();

        static void initialise (GLFWwindow* window);
    
        static void update ();
    
    private:
        static GamepadComponent  gamepad;
        static KeyboardComponent keyboard;
        static MouseComponent    mouse;
 
};

#endif
