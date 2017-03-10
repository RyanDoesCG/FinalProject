//
//  EngineTest.cpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "TriGeometry.hpp"
#include "QuadGeometry.hpp"
#include "EngineTest.hpp"
#include "AACollisionBox2D.hpp"

EngineTest::EngineTest (GraphicsEngine* g, PhysicsEngine* p) {
    triangle = new GraphicsObject(QuadGeometry(), Material("object", "rock.jpg"));
    collider = new AACollisionBox2D(1, 1);
    g->add(triangle);
    p->addTo2D(collider);
    
    triangle->wireframe(false);
}

EngineTest::~EngineTest () {
    
}

void EngineTest::update() {
    if (collider->colliding) {
        std::cout << "bang" << std::endl;
    }
}
