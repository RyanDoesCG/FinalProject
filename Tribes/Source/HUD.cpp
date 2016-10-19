/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"

/** 
 *  Make a Quad class?
 */
HUD::HUD (Game* g, int width, int height, float* d) : screenHeight(width), screenWidth(height) {
    textPipeline = TextRenderer ();
    delta = d;
    game  = g;
}

HUD::HUD (Game* g, int width, int height) : screenHeight(width), screenWidth(height) {
    textPipeline = TextRenderer ();
    game = g;
}

HUD::HUD () : screenWidth(0), screenHeight(0) {
    
}

HUD::~HUD () {

}

void HUD::update() {
    textPipeline.renderText("xpos: " + std::to_string((int)mouseX),        5, screenHeight / 1.8, 1);
    textPipeline.renderText("ypos: " + std::to_string((int)mouseY),        5, screenHeight / 1.9, 1);
    textPipeline.renderText(std::to_string((int)*delta) + " fps",          5, screenHeight / 2.02, 1);
    textPipeline.renderText("pre-alpha", 5, 9, 1);
    
    game->planet->getFlag()->update();
    textPipeline.renderText(game->planet->getName(), screenWidth / 0.88, screenHeight / 2.2, 1);

}

void HUD::updateMousePosition (float x, float y) {
    mouseX = x;
    mouseY = y;
}
