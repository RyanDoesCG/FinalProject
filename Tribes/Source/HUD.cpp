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
    this->game = game;
    
    addChild(new HUDElement("new game",  glm::vec2(16, 660)));
    addChild(new HUDElement("load game", glm::vec2(16, 590)));
    addChild(new HUDElement("options",   glm::vec2(16, 520)));
    addChild(new HUDElement("quit",      glm::vec2(16, 450)));

}

HUD::~HUD () {

}

void HUD::init () {
    textRenderer = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    
    initChildren();
    
    ((HUDElement*)children.at(0))->select();
}

void HUD::update (GameState state) {
    switch (state) {
        case MAIN_MENU:
            updateMainMenu ();
            break;
        case NEW_GAME:
            updateNewGame ();
            break;
        case LOAD_GAME:
            updateLoadGame ();
            break;
        case OPTIONS_SCREEN:
            updateOptionsScreen ();
            break;
        case IN_GAME:
            updateInGame();
            break;
        case IN_GAME_PAUSED:
            updateInGamePaused();
            break;
        case GAME_OVER:
            break;
    }
    
    // render elements
    Actor::update(state);
}

void HUD::updateMainMenu () {

}

void HUD::updateNewGame () {
    
}

void HUD::updateLoadGame () {
    
}

void HUD::updateOptionsScreen () {
    
}

void HUD::updateInGame () {
    // DEBUG UI
    textRenderer->renderTextAs2D("mouse x: " + std::to_string(mouse->getMouseX()), glm::vec2(10, 1040), glm::vec3(0.75, 0.75, 0.75), 0.32);
    textRenderer->renderTextAs2D("mouse y: " + std::to_string(mouse->getMouseY()), glm::vec2(10, 1005), glm::vec3(0.75, 0.75, 0.75), 0.32);
    textRenderer->renderTextAs2D("pre-alpha", glm::vec2(10, 8), 0.24);
    
    // handle events
    static int selected = 0;
    if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN)) {
        ((HUDElement*)children.at(selected))->unselect();
        
        selected = (selected + 1) % children.size();
        
        ((HUDElement*)children.at(selected))->select();
    }
    
    if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP)) {
        ((HUDElement*)children.at(selected))->unselect();
        
        if (selected == 0) selected = 3;
        else selected -= 1;
        
        ((HUDElement*)children.at(selected))->select();
    }
    
    if (keyboard->isKeyDown(GLFW_KEY_ENTER)) {
        switch (selected) {
            case 0:
                std::cout << "New Game\n";
                break;
            case 1:
                std::cout << "Load Game\n";
                break;
            case 2:
                std::cout << "Options\n";
                break;
            case 3:
                std::cout << "Exit\n";
                game->end(); // breaks for fuck knows why when called here
                break;
        }
    }
}

void HUD::updateInGamePaused () {
    textRenderer->renderTextAs2D("PAUSED", glm::vec2(960, 540), glm::vec3(0.8, 0.1, 0.1), 0.5);
}
