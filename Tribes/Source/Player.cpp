/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Player.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Player.hpp"
#include "../Headers/Engine/MouseInputComponent.hpp"

Player::Player  () {

}

Player::~Player () {

}

void Player::init() {
    std::cout << "Player Online" << std::endl;
    
    addComponent(new MouseInputComponent());
}

void Player::update() {
    Actor::update();
}
