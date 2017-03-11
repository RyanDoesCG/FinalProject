//
//  EngineTest.cpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "TriGeometry.hpp"
#include "QuadGeometry.hpp"
#include "CubeGeometry.hpp"
#include "EngineTest.hpp"
#include "AACollisionBox2D.hpp"

EngineTest::EngineTest (GraphicsEngine* g, PhysicsEngine* p) {
    triangle = new GraphicsObject(QuadGeometry(), Material("object", "rock.jpg"));
    collider = new AACollisionBox2D(1, 1);
    g->add(triangle);
    p->addTo2D(collider);
    
    triangle->colour = glm::vec4(0.21,0.21,0.21,1);
    
    triangle->position = glm::vec3(0, 0, 0);
    triangle->scale    = glm::vec3(1, 1, 1);
    
    triangle->wireframe(false);
}

EngineTest::~EngineTest () {
    
}

void EngineTest::update() {
    

}
