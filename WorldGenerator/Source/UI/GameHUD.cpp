/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameHUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/UI/GameHUD.hpp"
#include "../../Headers/Engine/Utility/Input.hpp"
GameHUD::GameHUD  (float width, float height, Game* game, Player* player, Planet* planet) {
    windowWidth  = width;
    windowHeight = height;
    textPipeline = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    
    this->player = player;
    this->planet = planet;
    this->game   = game;

    gamepad  = Input::getGamepadHandle();
    keyboard = Input::getKeyboardHandle();
    mouse    = Input::getMouseHandle();
}

GameHUD::~GameHUD () {

}

void GameHUD::draw (SceneCamera *camera) {
    switch (mode) {
        case 0: {
            textPipeline->renderTextAs2D("explore mode", glm::vec2(10, 10), vec3(0.32, 0.32, 0.32), 0.35);
            break;
        }
        case 1: {
            textPipeline->renderTextAs2D(planet->getName(), glm::vec2(25, 1000), vec3(0.9), 0.4);
            textPipeline->renderTextAs2D("edit mode", glm::vec2(10, 10), vec3(0.4, 0.4, 0.4), 0.35);
            break;
        }
    }
}

void GameHUD::update (GameState state) {
    switch (state) {
        case RUNNING_EDITMODE: {
            mode = 1;

            if (gamepad->isButtonDown(GAMEPAD_BUTTON_Y) || keyboard->isKeyDown(GLFW_KEY_E)) {
                planet->randomise();
                gamepad->buttonHandled(GAMEPAD_BUTTON_Y);
                keyboard->keyHandled(GLFW_KEY_E);
            }
            if (gamepad->isButtonDown(GAMEPAD_BUTTON_X) || keyboard->isKeyDown(GLFW_KEY_W)) {
                planet->toggleWater();
                gamepad->buttonHandled(GAMEPAD_BUTTON_X);
                keyboard->keyHandled(GLFW_KEY_W);
            }
            if (gamepad->isButtonDown(GAMEPAD_BUTTON_A) || keyboard->isKeyDown(GLFW_KEY_A)) {
                planet->toggleAtmos();
                gamepad->buttonHandled(GAMEPAD_BUTTON_A);
                keyboard->keyHandled(GLFW_KEY_A);
            }
            
            break;
        }
        case RUNNING_FREEMODE: {
            mode = 0;

            
            break;
        }
    }
    
    Actor::updateComponents();
}
