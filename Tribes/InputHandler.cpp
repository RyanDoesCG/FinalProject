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

InputHandler::InputHandler(Game* game) {
    this->activeKeys = new AVLTree();
    this->game = game;
}

InputHandler::~InputHandler () {
    free(activeKeys);
}

void InputHandler::checkInput() {
    while (false) {

    }
    
    handleKeys();
}

void InputHandler::handleKeys() {
/*    if (!activeKeys->isEmpty()) std::cout << "Tree Size: " << activeKeys->getSize() << "\n";

    if (activeKeys->contains(SDLK_w)) {
        std::cout << "w handled\n";
        game->getCamera()->moveForward();
    }
    
    if (activeKeys->contains(SDLK_a)) {
        std::cout << "a handled\n";
        game->getCamera()->moveLeft();
    }
    
    if (activeKeys->contains(SDLK_s)) {
        std::cout << "s handled\n";
        game->getCamera()->moveBack();
    }
    
    if (activeKeys->contains(SDLK_d)) {
        std::cout << "d handled\n";
        game->getCamera()->moveRight();
    }
    
    if (activeKeys->contains(SDLK_SPACE)) {
        std::cout << "space handled\n";
    }
    
    if (activeKeys->contains(SDLK_ESCAPE)) {
        game->pause();
    }*/
}
