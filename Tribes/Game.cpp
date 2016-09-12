/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Game.hpp"
#include "Mesh.hpp"

#include "PlanetGraphics.hpp"

Game::Game() {
    input  = new InputHandler(this);
    window = new Window(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "tribes"
    );
    
    camera = new Camera(
        glm::vec3(0, 0, -12),
        100.0f,
        (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,
        0.01f,
        1000.0f
    );
    
    // seed random generator ONCE PER RUN
    srand(static_cast<unsigned int>(time(0)));
    
    planet = new Planet(TOUGHER);
    planet->setGraphics(new PlanetGraphics());
    
    state  = RUNNING;
}

Game::~Game() {

}

void Game::begin() {

    while (state != ENDED) {
        input->checkInput();
        
        if (state == RUNNING) {
            // update objects
            
            // render objects
            window->clear();
            planet->draw();
            
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
    if (state == PAUSED) state = RUNNING;
    else if (state == RUNNING) state = PAUSED;
    std::cout << "pause msg received\n";
}
