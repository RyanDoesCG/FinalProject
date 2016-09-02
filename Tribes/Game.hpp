/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.hpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Game_hpp
#define Game_hpp

#include "InputHandler.hpp"
#include "Window.hpp"
#include <iostream>

enum State {
    RUNNING,
    PAUSED,
    ENDED
};

class Game {
    public:
        Game  ();
        ~Game ();
    
        void begin ();

    private:
        InputHandler* input;
        Window* window;
        State state;
};

#endif /* Game_hpp */
