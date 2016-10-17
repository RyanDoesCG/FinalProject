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

Game::Game() {
    // seed random generator & generate random seed
    srand(static_cast<unsigned int>(time(0)));
    seed = rand();
    
    // display seed and seed game
    std::cout << seed << std::endl;
    srand(seed);
    
    // put engine stuff together
    window = new Window       (SCREEN_WIDTH, SCREEN_HEIGHT, "tribes");
    planet = new Planet       (TOUGHER, seed);
    hud    = new HUD          (this, SCREEN_WIDTH, SCREEN_HEIGHT, &delta);
    input  = new InputHandler (this);
    state  = RUNNING;
    
    backdrop = new Backdrop(10000);
}

Game::~Game() {
    free(window);
    free(input);
    free(planet);
}

void Game::begin() {
    while (!window->shouldClose()) {
        float start = glfwGetTime();
        input->update();
        
        if (state == RUNNING) {
            window->clear();
            
            backdrop->update();
            planet->update();
            hud->update();
            
            window->update();
        }
        
        else {
            glfwWaitEvents();
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        
        delta = (glfwGetTime() - start) * 1000;
        //if (delta < 16) std::this_thread::sleep_for(std::chrono::milliseconds((int)(16 - delta)));
    }
}

void Game::end() {
    state = ENDED;
}

void Game::pause() {
    // toggle pause on and off
    if      (state ==  PAUSED) state = RUNNING;
    else if (state == RUNNING) state = PAUSED;
    std::cout << "pause msg received\n";
}

void Game::rotatePlanetLeft() {

}

void Game::rotatePlanetRight() {
    
}
