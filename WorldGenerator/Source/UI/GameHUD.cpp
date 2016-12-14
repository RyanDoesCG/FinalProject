/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameHUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/UI/GameHUD.hpp"

GameHUD::GameHUD  (float width, float height, Game* game, Player* player, Planet* planet) {
    windowWidth  = width;
    windowHeight = height;
    textPipeline = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    
    this->player = player;
    this->planet = planet;
    this->game   = game;
    
    /*
    leftUI = Quad();
    leftUI.setPosition(glm::vec3(-0.7, 0.0, 0));
    leftUI.setScale(glm::vec3(0.5, 1.75, 1.0));
    
    rightUI = Quad();
    rightUI.setPosition(glm::vec3(0.7, 0.0, 0));
    rightUI.setScale(glm::vec3(0.5, 1.75, 1.0));
     */
    
    menubarTop = Quad();
    menubarTop.setPosition(glm::vec3(0.0, 1.0, 0.0));
    menubarTop.setScale(glm::vec3(10, 0.5, 1.0));
    
    menubarBottom = Quad();
    menubarBottom.setPosition(glm::vec3(0.0, -1.15, 0.0));
    menubarBottom.setScale(glm::vec3(10, 0.5, 1.0));
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
            if (keyboard->isKeyDown(GLFW_KEY_E)) {
                planet->randomise();
                keyboard->keyHandled(GLFW_KEY_E);
            }
            
            break;
        }
        case RUNNING_FREEMODE: {
            mode = 0;
            if (gamepad->isButtonDown(GAMEPAD_BUTTON_Y)) {
                planet->randomise();
                gamepad->buttonHandled(GAMEPAD_BUTTON_Y);
            }
            
            break;
        }
    }
    
    Actor::updateComponents();
}
