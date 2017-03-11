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
    triangle = new GraphicsObject(CubeGeometry(), Material("object", "rock.jpg"));
    g->add(triangle);
    
    triangle->colour = glm::vec4(0.31,0.31,0.31, 1);
    
    triangle->position = glm::vec3(0, 0, -6);
    triangle->scale    = glm::vec3(4, 4, 4);
    
    triangle->wireframe(true);
}

EngineTest::~EngineTest () {
    
}

void EngineTest::update() {
    triangle->rotation.x = 0.25;
    triangle->rotation.y += 0.001;
}
