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
    terrain = new GraphicsObject(
        new ModelGeometry("sphere/uvsphere2"),
        new Material      ("sphere_vertextextured", "noise/2.jpg")
    );
    
    water = new GraphicsObject (
        new ModelGeometry ("sphere/uvsphere2"),
        new Material      ("object")
    );
    
    terrain->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    terrain->position = glm::vec3(0, 0, -20);
    terrain->scale    = glm::vec3(10, 10, 10);
    terrain->wireframe(true);
    
    //water->colour   = glm::vec4(0.65, 0.7, 0.88, 0.25);
    water->colour   = glm::vec4(1.0, 0.7, 0.7, 0.25);
    water->position = glm::vec3(0, 0, -20);
    water->scale    = glm::vec3(10, 10, 10);
    water->wireframe(false);
    
    g->add(terrain);
    g->add(water);
    
    mouse = InputManager::getMouseHandle();
    
    terrain->rotation.x = 0.25;
}

Planet::~Planet () {}

void Planet::update(State state) {
    
    switch (state) {
        case MENU: {
            GLfloat restx = 0;
            if (terrain->position.x > restx) { terrain->position.x -= (restx - terrain->position.x) * -0.05; }
            if (water->position.x > restx) { water->position.x -= (restx - water->position.x) * -0.05; }
            
            velocity.y += 0.0001;
            terrain->rotation += velocity;
            velocity *= 0.8;
            break;
        }
            
        case VIEW: {
            GLfloat restx = 6;
            if (terrain->position.x < restx) { terrain->position.x += (restx - terrain->position.x) * 0.05; }
            if (water->position.x   < restx) { water->position.x   += (restx - water->position.x) * 0.05; }
            
            velocity.y += 0.0001;
            if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
                velocity.y += 0.5 * mouse->getXoffset();
                terrain->scale += mouse->getYoffset() * 1.25;
            }
            
            velocity.y += 0.01 * mouse->getScrollX();
            terrain->scale += mouse->getScrollY() * 0.25;
            
            terrain->rotation += velocity;
            velocity *= 0.8;
            break;
        }
    }
    

}
