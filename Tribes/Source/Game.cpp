/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/PlanetGraphics.hpp"
#include "../Headers/Engine/Game.hpp"
#include "../Headers/Engine/Mesh.hpp"
#include "../Headers/GLFW/glfw3.h"

Game::Game() {
    // seed random generator & generate random seed
    srand(static_cast<unsigned int>(time(0)));
    seed = rand();
    std::cout << seed << std::endl;
    
    // put engine stuff together
    window = new Window       (SCREEN_WIDTH, SCREEN_HEIGHT, "tribes");
    input  = new InputHandler (this);
    planet = new Planet       (TOUGHER, seed);
    
    state  = RUNNING;
}

Game::~Game() {
    free(window);
    free(input);
    free(planet);
}

void Game::begin() {
    planet->toString();

    while (!window->shouldClose()) {
        input->update();
        
        if (state == RUNNING) {
            window->clear();
            planet->update();
            window->update();
        }
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
