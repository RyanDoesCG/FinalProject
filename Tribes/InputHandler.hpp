/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.hpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef InputHandler_hpp
#define InputHandler_hpp

#include "Window.hpp"

#include <SDL2/SDL.h>
#include <iostream>

class InputHandler {
    public:
        InputHandler  () {}
        ~InputHandler () {}

        void checkInput() {
            while (SDL_PollEvent (&event)) {
                switch (event.type) {
                    case SDL_MOUSEMOTION:
                        std::cout << "Mouse motion handled\n";
                        break;
                    case SDL_QUIT:
                        SDL_Quit(); // move elsewhere
                        break;
                }
            }
        }
    
    private:
        SDL_Event event;
};

#endif /* InputHandler_hpp */
