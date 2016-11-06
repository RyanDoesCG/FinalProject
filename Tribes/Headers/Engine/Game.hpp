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

#include "../GLEW/glew.h"
#include "../GLFW/glfw3.h"

#include "GameState.hpp"
#include "Actor.hpp"
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>

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

    inline long  getSeed  ();
    
    bool windowIsAlive();
    
private:
    typedef int actorID;
    
    int initGLFW ();
    int initGLEW ();
    
    int windowWidth;
    int windowHeight;

    GLFWwindow* window;
    GameState state;

    std::map<actorID, Actor*> worldActors;
    
    // world seed
    long generateSeed();
    long seed;

};

#endif /* Game_hpp */
