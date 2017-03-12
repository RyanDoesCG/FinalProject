//
//  Cursor.cpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Cursor.hpp"
#include "AACollisionBox2D.hpp"
#include "QuadGeometry.hpp"

Cursor::Cursor(GraphicsEngine* g, PhysicsEngine* p) {
    quad = new GraphicsObject(QuadGeometry(), Material("object"));
    collider = new AACollisionBox2D(glm::vec2(0.05));
    g->add(quad);
    p->addTo2D(collider);
    
    quad->position = glm::vec3(0, 0, 0.2);
    quad->colour   = glm::vec4(0.81, 0.81, 0.81, 1);
    quad->scale    = glm::vec3(0.05, 0.05, 0.05);
    
    gamepad = InputManager::getGamepadHandle();
    
    mouse = InputManager::getMouseHandle();
    mouse->hide();
}

Cursor::~Cursor() {
    
}

void Cursor::update() {
    quad->position.x += (mouse->getXoffset() == lastXoffset) ? 0 : mouse->getXoffset();
    quad->position.y += (mouse->getYoffset() == lastYoffset) ? 0 : mouse->getYoffset();
    quad->position.x += gamepad->getAxisState(LEFT_STICK_X_AXIS) * 0.05; gamepad->resetAxisState(LEFT_STICK_X_AXIS);
    quad->position.y -= gamepad->getAxisState(LEFT_STICK_Y_AXIS) * 0.05; gamepad->resetAxisState(LEFT_STICK_Y_AXIS);
    
    collider->position = quad->position;
    collider->position = quad->position;
    
    lastXoffset = mouse->getXoffset();
    lastYoffset = mouse->getYoffset();
    
    std::cout << collider->colliding << std::endl;
    
    if (collider->colliding) {
        quad->colour = glm::vec4(1.0, 0.81, 0.81, 1);
    } else {
        quad->colour   = glm::vec4(0.81, 0.81, 0.81, 1);
    }
}
