/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 05/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"
#include "../Headers/Engine/HUDElement.hpp"

HUD::HUD (GLFWwindow* window, Game* game) {
    mouse = (MouseInputComponent*)addComponent(new MouseInputComponent(window, game));
    keyboard = (KeyboardInputComponent*)addComponent(new KeyboardInputComponent(window, game));
    textRenderer = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    this->game = game;
    
}

HUD::~HUD () {

}

void HUD::init () {
    Actor::init();
}

void HUD::update (GameState state, SceneCamera* camera) {
    Actor::update(state, camera);
}
