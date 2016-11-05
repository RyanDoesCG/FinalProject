/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 05/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"

#include "../Headers/Engine/TextRenderingComponent.hpp"
#include "../Headers/Engine/MeshComponent.hpp"
#include "../Headers/Engine/ShaderComponent.hpp"

HUD::HUD  () {
    mainPane = {
    //   x     y    z     x     y    z     x      y    z
        -0.95, 0.9, 0.0, -0.25, 0.9, 0.0, -0.25, -0.9, 0.0, // TRIANGLE 1
        -0.95, 0.9, 0.0, -0.95, -0.9, 0.0, -0.25, -0.9, 0,0// TRIANGLE 2
    };
}

HUD::~HUD () {

}

void HUD::init () {
    addComponent(new TextRenderingComponent());
    
    //addComponent(new ShaderComponent("HUDPane"));
    //addComponent(new MeshComponent(&mainPane));
}

void HUD::update () {
/*
    // mock UI
    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("NEW GAME", glm::vec2(8, 340), glm::vec3(1.0, 1.0, 1.0), 0.9);
    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("LOAD GAME", glm::vec2(8, 310), glm::vec3(1.0, 1.0, 1.0), 0.9);
    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("OPTIONS", glm::vec2(8, 280), glm::vec3(1.0, 1.0, 1.0), 0.9);
    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("EXIT", glm::vec2(8, 250), glm::vec3(1.0, 1.0, 1.0), 0.9);
*/
    
    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("pre-alpha", glm::vec2(5, 5), 0.5);
    Actor::update();
}
