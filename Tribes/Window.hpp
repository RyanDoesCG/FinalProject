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

#include "glm/vec4.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class Window {
    public:
        Window  (int width, int height, const std::string& title);
        ~Window ();
    
        void update ();
        void clear  ();
    
        bool open;

    private:
        SDL_Window *  window;
        SDL_GLContext glContext;
    
        int width;
        int height;
    
        glm::vec4 * clearColor;
        std::string title;
    
        int initSDL();
        int initGLEW();

};

#endif /* Window_hpp */

/** 
 *  Nice Colours:
 *      - r: 0.52 g: 0.64 b: 0.49
 */
