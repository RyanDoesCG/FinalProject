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
#include <chrono>
#include <thread>

int getSeed() {
    // seed random generator & generate random seed
    srand(static_cast<unsigned int>(time(0)));
    return rand();
}

Game::Game() {
    seed = getSeed();
    std::cout << seed << std::endl;
    srand(seed);
    
    // put engine stuff together
    window = new Window       (SCREEN_WIDTH, SCREEN_HEIGHT, "tribes");
    planet = new Planet       (TOUGHER, seed);
    hud    = new HUD          (this, SCREEN_WIDTH, SCREEN_HEIGHT, &delta);
    input  = new InputHandler (this);
    state  = RUNNING;
    backdrop = new Backdrop(30000);
}

Game::~Game() {
    free(window);
    free(input);
    free(planet);
}

void Game::begin() {
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
        
        delta = (glfwGetTime() - start) * 1000;
    }
}

void Game::end() {
    state = ENDED;
}

// toggle pause on and off
void Game::pause() {
    if (state ==  PAUSED)
        state = RUNNING;
    else if (state == RUNNING)
        state = PAUSED;
}
