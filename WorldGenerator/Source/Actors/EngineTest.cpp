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
    graphics = new GraphicsObject(
        new ModelGeometry ("sphere/sphere"),
        new Material      ("object")
    );
    
    graphics->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 0, -30);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(true);
    
    g->add(graphics);
}

EngineTest::~EngineTest () {}

void EngineTest::update() {
    graphics->rotation.x = 0.25;
    graphics->rotation.y += 0.001;
}
