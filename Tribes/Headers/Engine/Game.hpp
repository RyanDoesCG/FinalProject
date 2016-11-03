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
#include "Planet.hpp"
#include "HUD.hpp"
#include <iostream>
#include <vector>

class HUD;

enum State { MENU, RUNNING, PAUSED, ENDED };
enum Build { CINEMATIC, DEVELOPMENT };

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
    
        inline GLFWwindow* getWindow   () { return window; }
        inline HUD*    getHUD          () { return hud; }
        inline State   getState        () { return state; }
        inline long    getSeed         () { return seed; }
    
        // REPLACE/RETHINK
        Planet*       planet;
        Backdrop*     backdrop;
        // REPLACE/RETHINK
    
        std::vector<GameObject> objects;
    
    private:
        int initGLFW ();
        int initGLEW ();
    
        int windowWidth;
        int windowHeight;
    
        InputHandler* input;
        HUD*          hud;
        GLFWwindow*   window;
        State         state;
    
        // for frame timing
        float delta;
        
        // world seed
        long generateSeed();
        long seed;
    
        void calculateFPS (float start);
};

#endif /* Game_hpp */
