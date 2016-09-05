/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "GameObject.hpp"

GameObject::GameObject (GraphicsComponent* graphics, PhysicsComponent* physics) {
    graphics  = graphics;
    physics   = physics;
    position  = new glm::vec3(0, 0, 0);
    transform = new Transform();
}
    
GameObject::GameObject () {
    position  = new glm::vec3(0, 0, 0);
    transform = new Transform();
}

GameObject::~GameObject () {
    // free (null) should be value but check for null to be safe
    if (graphics) free(graphics);
    if (physics) free(physics);
    free(transform);
    free(position);
}
    
void GameObject::update () {

}

void GameObject::render () {

}

void GameObject::setGraphics(GraphicsComponent* graphics) { this->graphics = graphics; }
void GameObject::setPhysics(PhysicsComponent* physics) { this->physics = physics; }
