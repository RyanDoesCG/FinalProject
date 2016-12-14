/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Cursor.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 14/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Cursor.hpp"

Cursor::Cursor (GLFWwindow* window, Game* game) {
    gamepad = new GamepadComponent();
    mouse   = new MouseComponent();
}

Cursor::~Cursor () {
    
}

void Cursor::draw(SceneCamera *camera) {
    
}

void Cursor::update(GameState state) {
    
    gamepad->update();
    mouse->update();
}
