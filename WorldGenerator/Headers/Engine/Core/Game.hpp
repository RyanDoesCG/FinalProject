/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Game_hpp
#define Game_hpp

#include "../../GLEW/glew.h"
#include "../../GLFW/glfw3.h"

#include "GameState.hpp"

enum Build { CINEMATIC, DEVELOPMENT };

    /**
     *  Game Class
     *
     */
class Game {
    public:
        Game ();
       ~Game ();

        void begin();
        void pause();
        void end();

        inline int getSeed ();
        inline void setSeed (int s) {seed = s;}
    
        bool windowIsAlive();
    
        int windowWidth;
        int windowHeight;
    
        void setState (GameState nextState);
    
    private:
        typedef int actorID;
    
        int initGLFW ();
        int initGLEW ();

        GLFWwindow* window;
        GameState state;
    
        // world seed
        int generateSeed();
        int seed;
    
};

#endif /* Game_hpp */
