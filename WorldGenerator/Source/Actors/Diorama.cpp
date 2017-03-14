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
    terrain = new GraphicsObject(
        new ModelGeometry ("plane/plane"),
        new Material      ("plane_vertextextured", "noise/test.jpg")
    );
    
    //trees = new ObjectSpawner (g, "trees/tree", glm::vec4(0.2, 0.4, 0.0, 1.0), 10);
    //trees = new ObjectSpawner (g, "trees/rock", glm::vec4(0.21, 0.21, 0.21, 1.0), 25);
    
    terrain->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    terrain->position = glm::vec3(0, 0, -10);
    terrain->scale    = glm::vec3(10, 10, 10);
    terrain->wireframe(true);
    
    g->add(terrain);
    
    mouse = InputManager::getMouseHandle();
    
    terrain->rotation.x = 0.25;
}

Diorama::~Diorama () {}

void Diorama::update(State state) {
    
    switch (state) {
        case MENU: {
            velocity.y += 0.0001;
            terrain->rotation += velocity;
            velocity *= 0.6;
            break;
        }
            
        case VIEW: {
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
