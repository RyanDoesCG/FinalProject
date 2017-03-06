//
//  Window.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "glew.h"
#include "glfw3.h"

class Window {
    public:
        Window (int width, int height);
       ~Window ();
    
        void close();
        bool isAlive();
        void swapBuffers();
    
        GLFWwindow* asGLFW () { return window; }
    
    private:
        int width;
        int height;
    
        int initGLEW ();
        int initGLFW ();
    
        GLFWwindow* window;
};

#endif /* Window_hpp */
