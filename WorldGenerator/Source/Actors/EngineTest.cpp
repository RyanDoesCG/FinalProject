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

#include "InputManager.hpp"

EngineTest::EngineTest (GraphicsEngine* g, PhysicsEngine* p) {
    graphics = new GraphicsObject(
        new ModelGeometry("sphere/uvsphere"),
        new Material      ("object_vertextextured", "rock.jpg")
    );
    
    graphics->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 0, -30);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(true);
    
    g->add(graphics);
    
    mouse = InputManager::getMouseHandle();
}

EngineTest::~EngineTest () {}

void EngineTest::update() {
    graphics->rotation.x = 0.25;
    graphics->rotation.y += 0.001;
    
    if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
        graphics->rotation.y += 0.5 * mouse->getXoffset();
    }
}
