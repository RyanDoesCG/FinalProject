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
        case MAIN_MENU: {
            mouse->showMouse();
            
            if (inGame) {
                camera->reset();
                inGame = false;
            }
            
            camera->pitch += mouse->getYoffset() * 0.1;
            camera->yaw   += mouse->getXoffset() * 0.1;
            break;
        }
        case RUNNING_FREEMODE: {
            mouse->hideMouse();
            
            if (!inGame) {mouse->centerMouse(); inGame = true;}
            
            if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP))    camera->moveForward();
            if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN))  camera->moveBackward();
            if (keyboard->isKeyDown(GLFW_KEY_A) || keyboard->isKeyDown(GLFW_KEY_LEFT))  camera->moveLeft();
            if (keyboard->isKeyDown(GLFW_KEY_D) || keyboard->isKeyDown(GLFW_KEY_RIGHT)) camera->moveRight();
            if (keyboard->isKeyDown(GLFW_KEY_R)) { camera->reset(); mouse->centerMouse();}
            if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {game->setState(MAIN_MENU);}
            
                // SWITCH MODE
            if (keyboard->isKeyDown(GLFW_KEY_Q)) {
                camera->reset();
                
                game->setState(RUNNING_EDITMODE);
                keyboard->keyHandled(GLFW_KEY_Q);
            }
            
            camera->yaw   += mouse->getXoffset();
            camera->pitch += mouse->getYoffset();
            
            break;
        }
        case RUNNING_EDITMODE: {
            mouse->showMouse();
            
            if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {game->setState(MAIN_MENU); camera->reset();}
            if (keyboard->isKeyDown(GLFW_KEY_Q)) {
                camera->reset();
                game->setState(RUNNING_FREEMODE);
                keyboard->keyHandled(GLFW_KEY_Q);
            }
            
            break;
        }
    }
    
    Actor::update(state, camera);
}
