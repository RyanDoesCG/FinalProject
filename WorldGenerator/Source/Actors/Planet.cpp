//
//  Planet.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Planet.hpp"
#include "PlaneGeometry.hpp"
#include "ModelGeometry.hpp"

Planet::Planet (GraphicsEngine* g) {
    graphics = new GraphicsObject(
        new ModelGeometry("sphere/uvsphere"),
        new Material      ("sphere_vertextextured", "noise/test.jpg")
    );
    
    graphics->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 0, -20);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(true);
    
    g->add(graphics);
    
    mouse = InputManager::getMouseHandle();
    
    graphics->rotation.x = 0.25;
}

Planet::~Planet () {}

void Planet::update(State state) {
    
    velocity.y += 0.001;
    
    if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
        velocity.y += 0.5 * mouse->getXoffset();
        graphics->scale += mouse->getYoffset() * 1.25;
    }
    
    graphics->rotation += velocity;
    velocity *= 0.8;
}
