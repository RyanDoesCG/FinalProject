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
#include "Backdrop.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include "HUD.hpp"
#include <iostream>

class HUD;

enum State { RUNNING, PAUSED, ENDED };
enum Build { CINEMATIC_MODE,  DEBUG_MODE };

// Deterines window size/debug hud
#define BUILD_MODE CINEMATIC_MODE

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
