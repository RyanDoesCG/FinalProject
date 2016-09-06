/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.cpp
 *  Tribes
 *
 *  Created by ryan needham on 03/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "InputHandler.hpp"
#include "Game.hpp"

InputHandler::InputHandler (Game* game) {
    this->activeKeys = new AVLTree();
    this->game = game;
}

InputHandler::~InputHandler () {
    free(activeKeys);
}

void InputHandler::checkInput() {
    while (SDL_PollEvent (&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                std::cout << "x: " << event.motion.x << "\n";
                std::cout << "y: " << event.motion.y << "\n\n";
                break;
            case SDL_KEYDOWN:
               // activeKeys->insert(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
               // activeKeys->remove(event.key.keysym.sym);
                break;
            case SDL_QUIT:
                game->end();
                break;
        }
    }
    
    if (!activeKeys->isEmpty()) handleKeys();
}

void InputHandler::handleKeys() {
    if (activeKeys->contains(SDLK_w)) {
        // move camera up/forward
    }
    
    if (activeKeys->contains(SDLK_a)) {
        // move camera left
    }
    
    if (activeKeys->contains(SDLK_s)) {
        // move camera right
    }
    
    if (activeKeys->contains(SDLK_d)) {
        // move camera down/back
    }
    
    if (activeKeys->contains(SDLK_ESCAPE)) {
        game->pause();
    }
}
