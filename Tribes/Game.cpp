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

Game::Game() {
    input  = new InputHandler(this);
    window = new Window(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "tribes"
    );
    
    state = RUNNING;
}

Game::~Game() {

}

void Game::begin() {
    while (state != ENDED) {
        input->checkInput();
        
        if (state == RUNNING) {
            // update
            window->clear();
            // draw
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
