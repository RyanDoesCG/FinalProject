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
    seed = generateSeed();
    std::cout << seed << std::endl;
    srand(seed);
    
    // put engine stuff together
    window   = new Window       (SCREEN_WIDTH, SCREEN_HEIGHT, "tribes");
    planet   = new Planet       (TOUGHER, seed);
    hud      = new HUD          (this, SCREEN_WIDTH, SCREEN_HEIGHT, &delta);
    input    = new InputHandler (this);
    backdrop = new Backdrop(20000);
    state    = RUNNING;
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
            calculateFPS(start);
        }
        
        else {
            glfwWaitEvents();
        }
    }
}

void Game::end() {
    state = ENDED;
}

// toggle pause on and off
void Game::pause() {
    state == RUNNING ? state = PAUSED : state = RUNNING;
}

void Game::calculateFPS (float start) {
    float smoothing = 0.9;
    delta = (delta * smoothing) + ((glfwGetTime() - start) * 1000 * (1.0-smoothing));
}

long Game::generateSeed() {
    srand(static_cast<unsigned int>(time(0)));
    return rand();
}
