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
    // free (null) should be value but
    // check for null to be safe
    if (graphics) free(graphics);
    if (physics)  free(physics);
    free(position);
    free(transform);
}
    
void GameObject::update (float time) {
    if (physics) physics->update(time);
    else std::cout << "No Physics Module" << "\n";
}

void GameObject::render () {
    if (graphics) graphics->render();
    else std::cout << "No Graphics Module" << "\n";
}

void GameObject::setGraphics(GraphicsComponent* graphics) {
    this->graphics = graphics;
}

void GameObject::setPhysics(PhysicsComponent* physics) {
    this->physics = physics;
}
