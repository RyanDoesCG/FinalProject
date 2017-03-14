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
        new ModelGeometry("sphere/uvsphere2"),
        new Material      ("sphere_vertextextured", "noise/2.jpg")
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
    
    switch (state) {
        case MENU: {
            GLfloat restx = 0;
            if (graphics->position.x > restx) { graphics->position.x -= (restx - graphics->position.x) * -0.05; }
            
            velocity.y += 0.0001;
            graphics->rotation += velocity;
            velocity *= 0.8;
            break;
        }
            
        case VIEW: {
            GLfloat restx = 6;
            if (graphics->position.x < restx) { graphics->position.x += (restx - graphics->position.x) * 0.05; }
            
            velocity.y += 0.0001;
            if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
                velocity.y += 0.5 * mouse->getXoffset();
                graphics->scale += mouse->getYoffset() * 1.25;
            }
            
            velocity.y += 0.01 * mouse->getScrollX();
            graphics->scale += mouse->getScrollY() * 0.25;
            
            graphics->rotation += velocity;
            velocity *= 0.8;
            break;
        }
    }
    

}
