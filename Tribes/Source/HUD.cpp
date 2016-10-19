/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"

/** 
 *  Make a Quad class?
 */

HUD::HUD  (Game* g, int width, int height, float* d) : screenHeight(width), screenWidth(height) {
    textPipeline = TextRenderer ();
    delta = d;
    game  = g;
}

HUD::HUD  (Game* g, int width, int height) : screenHeight(width), screenWidth(height) {
    textPipeline = TextRenderer ();
    game = g;
}

HUD::HUD () : screenWidth(0), screenHeight(0) {
    
}

HUD::~HUD () {

}

void HUD::update() {
    textPipeline.renderText("frame time: " + std::to_string(*delta) + "ms", 5, screenHeight - 390, 1);
    textPipeline.renderText("xpos: "       + std::to_string(mouseX), 5, screenHeight - 416, 1);
    textPipeline.renderText("ypos: "       + std::to_string(mouseY), 5, screenHeight - 442, 1);
    
    textPipeline.renderText("pre-alpha", 5, 9, 1);
    
    game->planet->getFlag()->update();
    
    textPipeline.renderText(game->planet->getName(), screenWidth + 115, screenHeight - 500, 1);

}

void HUD::updateMousePosition (float x, float y) {
    mouseX = x;
    mouseY = y;
}
