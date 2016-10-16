/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Backdrop.cpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Backdrop.hpp"
#include "../Headers/Engine/BackdropGraphics.hpp"

Backdrop::Backdrop  (int quality) {
    this->graphics = new BackdropGraphics(quality);
}

Backdrop::~Backdrop () {

}

void Backdrop::update() {
    if (graphics) graphics->draw();
}
