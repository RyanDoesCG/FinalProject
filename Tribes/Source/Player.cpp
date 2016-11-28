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
}

Player::~Player () {

}

void Player::init () {
    std::cout << "Player Online" << std::endl;

}

void Player::update(GameState state, SceneCamera* camera) {
    if (state == RUNNING) {
        // DEBUG SCENE NAVIGATION
        if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP))    camera->moveForward();
        if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN))  camera->moveBackward();
        if (keyboard->isKeyDown(GLFW_KEY_A) || keyboard->isKeyDown(GLFW_KEY_LEFT))  camera->moveLeft();
        if (keyboard->isKeyDown(GLFW_KEY_D) || keyboard->isKeyDown(GLFW_KEY_RIGHT)) camera->moveRight();
        if (keyboard->isKeyDown(GLFW_KEY_SPACE)) {
            camera->idling = !camera->idling;
            keyboard->keyHandled(GLFW_KEY_SPACE);
        }
        
        camera->pitch += mouse->getYoffset();
        camera->yaw   += mouse->getXoffset();
    }
    
    Actor::update(state, camera);
}
