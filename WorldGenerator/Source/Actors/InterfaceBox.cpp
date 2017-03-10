//
//  InterfaceBox.cpp
//  WorldGenerator
//
//  Created by user on 07/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "InterfaceBox.hpp"
#include "QuadGeometry.hpp"
#include "AACollisionBox2D.hpp"

InterfaceBox::InterfaceBox(GraphicsEngine* g, PhysicsEngine* p) {
    graphics = new GraphicsObject(
        QuadGeometry(),
        Material("object")
    );
    
    graphics->colour = glm::vec4(0.21, 0.21, 0.21, 1.0);
    
    physics = new AACollisionBox2D(10, 10);
    
    g->add(graphics);
    p->addTo2D(physics);
}

InterfaceBox::~InterfaceBox() {
    
}

void InterfaceBox::update() {
    graphics->position = physics->position;
}
