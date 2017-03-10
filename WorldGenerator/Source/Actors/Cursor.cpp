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
    quad = new GraphicsObject(QuadGeometry(), Material("object", ""));
    collider = new AACollisionBox2D(1, 1);
    g->add(quad);
    p->addTo2D(collider);
}

Cursor::~Cursor() {
    
}

void Cursor::update() {
    if (collider->colliding) {
        std::cout << "bang" << std::endl;
    }
}
