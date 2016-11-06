/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 05/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"

HUD::HUD (GLFWwindow* window, Game* game) {
    mouse = (MouseInputComponent*)addComponent(new MouseInputComponent(window, game));
    keyboard = (KeyboardInputComponent*)addComponent(new KeyboardInputComponent(window, game));
    
/*
    mainPane = {
    //   x     y    z     x     y    z     x      y    z
        -0.95, 0.9, 0.0, -0.25, 0.9, 0.0, -0.25, -0.9, 0.0, // TRIANGLE 1
        -0.95, 0.9, 0.0, -0.95, -0.9, 0.0, -0.25, -0.9, 0,0// TRIANGLE 2
    };
*/
}

HUD::~HUD () {

}

void HUD::init () {
    textRenderer = (TextRenderingComponent*)addComponent(new TextRenderingComponent());

    //addComponent(new ShaderComponent("HUDPane"));
    //addComponent(new MeshComponent(&mainPane));
}

void HUD::update () {
    textRenderer->renderTextAs2D("mouse x: " + std::to_string(mouse->getMouseX()), glm::vec2(5, 580), glm::vec3(0.75, 0.75, 0.75), 0.75);
    textRenderer->renderTextAs2D("mouse y: " + std::to_string(mouse->getMouseY()), glm::vec2(5, 560), glm::vec3(0.75, 0.75, 0.75), 0.75);

    // mock UI
    textRenderer->renderTextAs2D("NEW GAME", glm::vec2(8, 340), glm::vec3(0.001, 0.001, 0.001), 0.9);
    textRenderer->renderTextAs2D("LOAD GAME", glm::vec2(8, 310), glm::vec3(0.001, 0.001, 0.001), 0.9);
    textRenderer->renderTextAs2D("OPTIONS", glm::vec2(8, 280), glm::vec3(0.001, 0.001, 0.001), 0.9);
    textRenderer->renderTextAs2D("EXIT", glm::vec2(8, 250), glm::vec3(0.001, 0.001, 0.001), 0.9);

    
    textRenderer->renderTextAs2D("pre-alpha", glm::vec2(5, 5), 0.5);
    Actor::update();
}
