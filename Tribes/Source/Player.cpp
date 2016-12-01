/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Player.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Player.hpp"

Player::Player (GLFWwindow* window, Game* game) {
    mouse = (MouseInputComponent*)addComponent(new MouseInputComponent(window, game));
    keyboard = (KeyboardInputComponent*)addComponent(new KeyboardInputComponent(window, game));
    camera = (SceneCamera*)addChild(new SceneCamera(game->windowWidth, game->windowHeight));
    
    this->game = game;
}

Player::~Player () {

}

void Player::init () {
    std::cout << "Player Online" << std::endl;

}

void Player::update(GameState state, SceneCamera* camera) {
    switch (state) {
        case MAIN_MENU:
            inGame = false;
        
            camera->pitch += mouse->getYoffset() * 0.1;
            camera->yaw   += mouse->getXoffset() * 0.1;
            break;
        case RUNNING:
            if (!inGame) {mouse->centerMouse(); inGame = true;}
        
            if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP))    camera->moveForward();
            if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN))  camera->moveBackward();
            if (keyboard->isKeyDown(GLFW_KEY_A) || keyboard->isKeyDown(GLFW_KEY_LEFT))  camera->moveLeft();
            if (keyboard->isKeyDown(GLFW_KEY_D) || keyboard->isKeyDown(GLFW_KEY_RIGHT)) camera->moveRight();
            if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {game->setState(MAIN_MENU);}
            
            camera->pitch += mouse->getYoffset();
            camera->yaw   += mouse->getXoffset();
            break;
    }
    
    Actor::update(state, camera);
}
