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
HUD::HUD (Game* g,float* d) {
    textPipeline = TextRenderer ();
    delta = d;
    game  = g;
    
    // get window size
    glfwGetWindowSize(game->getWindow(), &screenWidth, &screenHeight);
}

HUD::HUD (Game* g)  {
    textPipeline = TextRenderer ();
    game = g;
}

HUD::HUD () {}

HUD::~HUD () {}

void HUD::update() {
    textPipeline.renderText("World Seed: " + std::to_string(game->getSeed()), 5, screenHeight, 1);
    textPipeline.renderText("xpos: "       + std::to_string((int)mouseX),     5, screenHeight, 1);
    textPipeline.renderText("ypos: "       + std::to_string((int)mouseY),     5, screenHeight, 1);
    textPipeline.renderText(std::to_string((int)*delta) + " mspf",            5, screenHeight, 1);
    textPipeline.renderText("pre-alpha", 5, 9, 1);
    
    game->planet->getFlag()->update();
    textPipeline.renderText(game->planet->getName(), screenWidth * 1.365, screenHeight * 0.55, 1);

}

void HUD::updateMousePosition (float x, float y) {
    mouseX = x;
    mouseY = y;
}
