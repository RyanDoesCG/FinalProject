//
//  Diorama.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Diorama.hpp"
#include "PlaneGeometry.hpp"
#include "ModelGeometry.hpp"

Diorama::Diorama (GraphicsEngine* g) {
    graphics = new GraphicsObject(
        new ModelGeometry("plane/plane"),
        new Material      ("plane_vertextextured", "noise/test.jpg")
    );
    
    graphics->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 0, -10);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(true);
    
    g->add(graphics);
    
    mouse = InputManager::getMouseHandle();
    
    graphics->rotation.x = 0.25;
}

Diorama::~Diorama () {}

void Diorama::update(State state) {
    
    switch (state) {
        case MENU: {
            velocity.y += 0.0001;
            graphics->rotation += velocity;
            velocity *= 0.6;
            break;
        }
            
        case VIEW: {
            velocity.y += 0.0001;
            if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
                velocity.y += 0.5 * mouse->getXoffset();
                graphics->scale += mouse->getYoffset() * 1.25;
            }
            graphics->rotation += velocity;
            velocity *= 0.8;
            break;
        }
    }
}
