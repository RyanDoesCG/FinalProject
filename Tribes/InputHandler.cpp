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
                activeKeys->insert(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                activeKeys->remove(event.key.keysym.sym);
                break;
            case SDL_QUIT:
                game->end();
                break;
        }
    }
    
    handleKeys();
}

void InputHandler::handleKeys() {
    if (!activeKeys->isEmpty())
        std::cout << "Tree Size: " << activeKeys->getSize() << "\n";

    if (activeKeys->contains(SDLK_w)) { std::cout << "w handled\n"; }
    if (activeKeys->contains(SDLK_a)) { std::cout << "a handled\n"; }
    if (activeKeys->contains(SDLK_s)) { std::cout << "s handled\n"; }
    if (activeKeys->contains(SDLK_d)) { std::cout << "d handled\n"; }
    if (activeKeys->contains(SDLK_SPACE)) { std::cout << "space handled\n"; }
    if (activeKeys->contains(SDLK_ESCAPE)) { game->pause(); }
}
