//
//  Keyboard.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Keyboard_hpp
#define Keyboard_hpp

#include "glfw3.h"

class Keyboard  {
    public:
        Keyboard ();
       ~Keyboard ();
    
        void attach (GLFWwindow* window);
        void update ();
    
        bool isKeyDown  (int keycode);
        void keyHandled (int keycode);
    
};

#endif /* Keyboard_hpp */
