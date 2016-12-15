/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Cursor.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 14/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Cursor.hpp"
#include "../../Headers/Engine/Utility/Input.hpp"

Cursor::Cursor () {
    gamepad = Input::getGamepadHandle();
    mouse   = Input::getMouseHandle();
    
    sprite = Quad();
}

Cursor::~Cursor () {
    
}

void Cursor::draw(SceneCamera *camera) {
    sprite.draw(camera);
}

void Cursor::update(GameState state) {
    
    gamepad->update();
    mouse->update();
    
    sprite.update(state);
}
