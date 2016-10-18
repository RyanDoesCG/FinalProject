/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Window.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Window_hpp
#define Window_hpp

#include "../GLM/vec4.hpp"
#include "../GLFW/glfw3.h"

#include <iostream>

class Window {
    public:
        Window  (int width, int height, const std::string& title);
        ~Window ();
    
        void update ();
        void clear  ();
    
        bool finished();

        inline GLFWwindow* getWindow() { return window; }
        void randomiseClearColour ();
    
        inline int getWidth  () { return width; }
        inline int getHeight () { return height; }
    
    private:
        GLFWwindow* window;
    
        int width;
        int height;
    
        glm::vec4   clearColour;
        std::string title;
    
        int initGLFW();
        int initGLEW();

};

#endif /* Window_hpp */

/** 
 *  Nice Colours:
 *      - r: 0.52 g: 0.64 b: 0.49
 *      - r: 0.64 g: 0.1  b: 0.24
 *      - r: 0.67 g: 0.61 b: 0.71
 *      - r: 0.8 g: 0.69 b: 0.57
 *      r: 0.82 g: 0.54 b: 0.15
 */
