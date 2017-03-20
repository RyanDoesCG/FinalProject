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
#include "ShaderCache.hpp"

Cursor::Cursor(GraphicsEngine* g, PhysicsEngine* p) {
    quad = new GraphicsObject (
        new QuadGeometry(),
        new Material(ShaderCache::loadBasicShader("object"))
    );
    
    collider = new AACollisionBox2D(glm::vec2(0.05));
    g->addToUI(quad);
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

void Cursor::update(State state) {
    quad->position.x += (mouse->getXoffset() == lastXoffset) ? 0 : mouse->getXoffset();
    quad->position.y += (mouse->getYoffset() == lastYoffset) ? 0 : mouse->getYoffset();
    quad->position.x += gamepad->getAxisState(LEFT_STICK_X_AXIS) * 0.05; gamepad->resetAxisState(LEFT_STICK_X_AXIS);
    quad->position.y -= gamepad->getAxisState(LEFT_STICK_Y_AXIS) * 0.05; gamepad->resetAxisState(LEFT_STICK_Y_AXIS);
    
    if (quad->position.x > maxX) quad->position.x = maxX;
    if (quad->position.x < minX) quad->position.x = minX;
    if (quad->position.y > maxY) quad->position.y = maxY;
    if (quad->position.y < minY) quad->position.y = minY;
    
    collider->position = quad->position;
    collider->position = quad->position;
    
    lastXoffset = mouse->getXoffset();
    lastYoffset = mouse->getYoffset();
    
    std::cout << collider->colliding << std::endl;
    
    if (collider->colliding) quad->colour = glm::vec4(1.0, 0.81, 0.81, 1);
    else quad->colour = glm::vec4(0.81, 0.81, 0.81, 1);
}
