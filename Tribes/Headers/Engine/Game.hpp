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
#include "TextRenderer.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include "HUD.hpp"
#include <iostream>
#include <vector>

#define SCREEN_WIDTH  960
#define SCREEN_HEIGHT 540

class HUD;
class Game {
    public:
        Game  ();
        ~Game ();
    
        void begin ();
        void end ();
    
        void pause ();
    
        inline Window* getWindowObject () {return window;}
        inline HUD* getHUD () { return hud; }
    
        void rotatePlanetLeft();
        void rotatePlanetRight();

        // FIND A BETTER SOLUTION TO INPUT 
        Planet*       planet;

    private:
        enum State {
            ENDED,
            RUNNING,
            PAUSED
        };
    
        // world seed
        long seed;
    
        // engine systems
        InputHandler* input;
        TextRenderer* text;
        HUD*          hud;
        Window*       window;
        State         state;
    
        // for frame timing
        float delta;
};

#endif /* Game_hpp */
