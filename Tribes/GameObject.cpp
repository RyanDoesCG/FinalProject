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
    // free (null) should be valid but check for null to be safe
    /* Should the deletion of an object lead the components of such
    ab i*/
    if (graphics) free(graphics);
    if (physics) free(physics);
    free(transform);
    free(position);
}
    
void GameObject::update () {

}

void GameObject::render () {
    if (graphics)
        graphics->draw();
    else
        std::cout << "GRAPHICS ERROR: No graphics module";
}

void GameObject::setGraphics (GraphicsComponent* graphics) {
    this->graphics = graphics;
//    std::cout << "Graphics Module Online\n";
}

void GameObject::setPhysics (PhysicsComponent* physics) {
    this->physics  = physics;
//    std::cout << "Physics Module Online\n";
}
