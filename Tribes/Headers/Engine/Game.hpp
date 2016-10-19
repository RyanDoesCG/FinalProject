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
#include "Backdrop.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include "HUD.hpp"
#include <iostream>

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 576

class HUD;
enum  State {
    RUNNING,
    PAUSED,
    ENDED
};

/**
 *  Game Class
 *
 */
class Game {
    public:
        Game  ();
        ~Game ();
    
        void begin ();
        void pause ();
        void end   ();
    
        inline Window* getWindowObject () {return window;}
        inline HUD*    getHUD          () {return hud;}
        inline State   getState        () {return state;}
    
        // REPLACE/RETHINK
        Planet*       planet;
        Backdrop*     backdrop;
        // REPLACE/RETHINK
    
    private:
        // engine systems
        InputHandler* input;
        TextRenderer* text;
        HUD*          hud;
        Window*       window;
        State         state;
    
        // for frame timing
        float delta;
        // world seed
        long generateSeed();
        long seed;
    
        void calculateFPS (float start);
};

#endif /* Game_hpp */
