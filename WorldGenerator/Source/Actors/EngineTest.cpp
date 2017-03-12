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
#include "PlaneGeometry.hpp"
#include "EngineTest.hpp"
#include "AACollisionBox2D.hpp"

#include "AsteroidGeometry.hpp"
#include "ModelGeometry.hpp"

EngineTest::EngineTest (GraphicsEngine* g, PhysicsEngine* p) {
    triangle = new GraphicsObject(ModelGeometry("sphere/sphere"), Material("object"));
    g->add(triangle);
    
    triangle->colour = glm::vec4(0.31,0.31,0.31, 1);
    
    triangle->position = glm::vec3(0, 0, -30);
    triangle->scale    = glm::vec3(10, 10, 10);
    
    triangle->wireframe(true);
}

EngineTest::~EngineTest () {
    
}

void EngineTest::update() {
    triangle->rotation.x = 0.25;
    triangle->rotation.y += 0.001;
}
