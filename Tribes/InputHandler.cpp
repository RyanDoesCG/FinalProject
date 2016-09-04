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
    this->game = game;
}

InputHandler::~InputHandler () {

}

void InputHandler::checkInput() {
    while (SDL_PollEvent (&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                std::cout << "x: " << event.motion.x << "\n";
                std::cout << "y: " << event.motion.y << "\n\n";
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    game->pause();
                break;
            case SDL_QUIT:
                game->end();
                break;
        }
    }
}
