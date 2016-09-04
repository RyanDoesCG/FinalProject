/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.hpp
 *  Tribes
 *
 *  Created by ryan needham on 03/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <SDL2/SDL.h>
#include <iostream>

class Game;

class InputHandler {
    public:
        InputHandler  (Game* game);
        ~InputHandler ();

        void checkInput();
    
    private:
        SDL_Event event;
        Game* game;
};

#endif /* InputHandler_h */
