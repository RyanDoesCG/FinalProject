/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PlanetGraphics.hpp"
#include "Game.hpp"
#include "Mesh.hpp"

#include "GLFW/glfw3.h"

/** 
 *  RNG should only be seeded once per run
 */
Game::Game() {
    srand(static_cast<unsigned int>(time(0)));
    window = new Window (
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "tribes"
    );
    
    camera = new Camera (
        glm::vec3(0, 0, -12),
        100.0f,
        (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,
        0.01f,
        1000.0f
    );
    
    input  = new InputHandler (
        this
    );
    
    state  = RUNNING;
    
    // Game Entities
    planet = new Planet(TOUGHER);
}

Game::~Game() {

}

void Game::begin() {
    planet->toString();
    
    while (!window->shouldClose()) {
        input->checkInput();
        if (state == RUNNING) {
            // update objects
            
            window->clear();
            // render objects
            planet->render();
            
            // swap buffers
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
