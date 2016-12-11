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
    mouse = (MouseComponent*)addComponent(new MouseComponent(window, game));
    keyboard = (KeyboardCopmonent*)addComponent(new KeyboardCopmonent(window, game));
    camera = (SceneCamera*)addChild(new SceneCamera(game->windowWidth, game->windowHeight));
    
    gamepad = (GamepadComponent*)addComponent(new GamepadComponent(window, game));
    
    this->game = game;
    inGame = false;
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
            // YAW
            if (gamepad->getAxisState(RIGHT_STICK_X_AXIS) > 0.01 ||
                gamepad->getAxisState(RIGHT_STICK_X_AXIS) < -0.01) {
                camera->yaw += gamepad->getAxisState(RIGHT_STICK_X_AXIS) * 0.1;
            }
            // PITCH
            if (gamepad->getAxisState(RIGHT_STICK_Y_AXIS) > 0.01 ||
                gamepad->getAxisState(RIGHT_STICK_Y_AXIS) < -0.01) {
                camera->pitch += gamepad->getAxisState(RIGHT_STICK_Y_AXIS) * 0.1;
            }
            break;
        }
        case RUNNING_FREEMODE: {
            mouse->hideMouse();
            
            // KEYBOARD
            if (!inGame) {camera->reset(); inGame = true;}
            if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP))    camera->moveForward();
            if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN))  camera->moveBackward();
            if (keyboard->isKeyDown(GLFW_KEY_A) || keyboard->isKeyDown(GLFW_KEY_LEFT))  camera->moveLeft();
            if (keyboard->isKeyDown(GLFW_KEY_D) || keyboard->isKeyDown(GLFW_KEY_RIGHT)) camera->moveRight();
            if (keyboard->isKeyDown(GLFW_KEY_R)) { camera->reset(); mouse->centerMouse();}
            if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {game->setState(MAIN_MENU);}
            if (keyboard->isKeyDown(GLFW_KEY_Q)) {
                // switch mode
                game->setState(RUNNING_EDITMODE);
                keyboard->keyHandled(GLFW_KEY_Q);
            }
            
            // MOUSE
            camera->yaw   += mouse->getXoffset();
            camera->pitch += mouse->getYoffset();
            
            // GAMEPAD
            if (gamepad->isButtonDown(GAMEPAD_SPECIAL_BACK)) {
                // switch mode
                game->setState(RUNNING_EDITMODE);
                gamepad->buttonHandled(GAMEPAD_SPECIAL_BACK);
            }
            
            if (gamepad->isButtonDown(GAMEPAD_SPECIAL_HOME)) {game->setState(MAIN_MENU); camera->reset();}
            
            // forward/backward
            if (gamepad->getAxisState(RIGHT_TRIGGER) > 0.01) { camera->moveForwardAt(gamepad->getAxisState(RIGHT_TRIGGER)); }
            if (gamepad->getAxisState(LEFT_TRIGGER) > 0.01) { camera->moveBackwardAt(gamepad->getAxisState(LEFT_TRIGGER)); }
            
            // YAW
            if (gamepad->getAxisState(LEFT_STICK_X_AXIS) > 0.03 ||
                gamepad->getAxisState(LEFT_STICK_X_AXIS) < -0.03) {
                camera->yaw += gamepad->getAxisState(LEFT_STICK_X_AXIS);
            }
            
            // PITCH
            if (gamepad->getAxisState(LEFT_STICK_Y_AXIS) > 0.03 ||
                gamepad->getAxisState(LEFT_STICK_Y_AXIS) < -0.03) {
                camera->pitch += gamepad->getAxisState(LEFT_STICK_Y_AXIS);
            }
            
            // ROLL
            if (gamepad->isButtonDown(GAMEPAD_RIGHT_BUMPER)) {
                camera->roll += 1;
            }
            
            if (gamepad->isButtonDown(GAMEPAD_LEFT_BUMPER)) {
                camera->roll -= 1;
            }
            
            // BAD BAD BAD
            setPosition(camera->getPosition());
            break;
        }
        case RUNNING_EDITMODE: {
            mouse->showMouse();
            
            // KEYBOARD
            if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {game->setState(MAIN_MENU); camera->reset();}
            if (keyboard->isKeyDown(GLFW_KEY_Q)) {
                game->setState(RUNNING_FREEMODE);
                keyboard->keyHandled(GLFW_KEY_Q);
            }
            
            // MOUSE
            
            // GAMEPAD
            if (gamepad->isButtonDown(GAMEPAD_SPECIAL_BACK)) {
                // switch mode
                game->setState(RUNNING_FREEMODE);
                gamepad->buttonHandled(GAMEPAD_SPECIAL_BACK);
            }
            
            if (gamepad->isButtonDown(GAMEPAD_SPECIAL_HOME)) {game->setState(MAIN_MENU); camera->reset();}
            
            break;
        }
    }
    
    Actor::update(state, camera);
}
