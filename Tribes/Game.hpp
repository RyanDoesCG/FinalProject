/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.hpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Game_hpp
#define Game_hpp

#include "InputHandler.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include <iostream>
#include <vector>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

class Game {
    public:
        Game  ();
        ~Game ();
    
        void begin ();
        void end ();
    
        void pause ();
    
    Camera* getCamera () {return camera;}

    private:
        enum State {
            ENDED,
            RUNNING,
            PAUSED
        };
    
        InputHandler* input;
        Window*       window;
        Camera*       camera;
        State         state;
        Planet*       planet;
};

#endif /* Game_hpp */
