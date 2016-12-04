/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameHUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 04/12/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/GameHUD.hpp"

GameHUD::GameHUD  (float width, float height, Game* game) {
    windowWidth  = width;
    windowHeight = height;
    textPipeline = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    this->game   = game;

}

GameHUD::~GameHUD () {

}

void GameHUD::update(GameState state, SceneCamera *camera) {
    switch (state) {
        case RUNNING_EDITMODE:
            textPipeline->renderTextAs2D("edit mode", glm::vec2(10, 10), vec3(0.32, 0.32, 0.32), 0.35);
            break;
        case RUNNING_FREEMODE:
            textPipeline->renderTextAs2D("explore mode", glm::vec2(10, 10), vec3(0.32, 0.32, 0.32), 0.35);
            break;
    }
    
    Actor::update(state, camera);
}
