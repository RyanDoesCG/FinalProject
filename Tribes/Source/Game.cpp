/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Game.hpp"
#include "../Headers/GLFW/glfw3.h"

Game::Game() {
    seed = generateSeed();
    std::cout << "World Seed: " << seed << std::endl << std::endl;
    srand(seed);
    
    // put engine stuff together
    if (BUILD_MODE == CINEMATIC) {
        window   = new Window   (1920, 1400, "tribes - cinematic");
        backdrop = new Backdrop (40000);
        hud      = new HUD      (this, 1920, 1080, &delta);
    }
    
    else if (BUILD_MODE == DEVELOPMENT) {
        window   = new Window   (848, 480, "tribes - debug");
        backdrop = new Backdrop (20000);
        hud      = new HUD      (this, 848, 480, &delta);
    }
    
    planet   = new Planet (TOUGHER, seed);
    input    = new InputHandler (this);
    state    = RUNNING;
}

Game::~Game() {
    free(window);
    free(input);
    free(planet);
}

void Game::begin() {

    // fucks up on vsync and just spins mad CPU - FIX THIS
    while (!window->finished()) {
        float start = glfwGetTime();
        input->update();
        
        if (state == RUNNING) {
            window->clear();
            
            backdrop->update(); // draw stars
            planet->update();   // draw planet
            hud->update();      // draw hud
            
            window->update();
        }
        
        else {
            glfwWaitEvents();
        }

        calculateFPS(start);
    }
}

void Game::end() {
    state = ENDED;
}

// toggle pause on and off
void Game::pause() {
    (state == RUNNING) ?
        state = PAUSED
    :
        state = RUNNING;
}

void Game::calculateFPS (float start) {
  //  BROKEN
   //float smoothing = 0.7;
   //delta = (delta * smoothing) + ((glfwGetTime() - start) * 1000 * (1.0-smoothing));

   delta = (glfwGetTime() - start) * 1000;
}

long Game::generateSeed() {
    srand(static_cast<unsigned int>(time(0)));
    return rand();
}
