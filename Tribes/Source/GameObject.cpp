/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/GameObject.hpp"

GameObject::GameObject () {
    graphics = nullptr;
    physics  = nullptr;
    position = glm::mat4();
}

GameObject::~GameObject () {
    if (graphics) free(graphics);
    if (physics)  free(physics);
}
    
void GameObject::update () {
    if (graphics) graphics->draw();
    if (physics)  physics->update();
}

void GameObject::setGraphics (GraphicsComponent* graphics) { this->graphics = graphics; }
void GameObject::setPhysics  (PhysicsComponent* physics)   { this->physics  = physics; }
