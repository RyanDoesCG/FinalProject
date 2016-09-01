/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "GameObject.hpp"

GameObject::GameObject  () {

}

GameObject::~GameObject () {

}

void GameObject::update () {
    this->physicsComponent->update();
}

void GameObject::render () {
    this->graphicsComponent->render();
}
