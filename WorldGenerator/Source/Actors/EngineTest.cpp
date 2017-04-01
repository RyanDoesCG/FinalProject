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

#include "ShaderCache.hpp"

EngineTest::EngineTest (GraphicsEngine* g, PhysicsEngine* p) {
    graphics = new GraphicsObject(
        new ModelGeometry ("sphere/uvsphere"),
        new Material      (ShaderCache::loadBasicShader("object_textured"), "rock.jpg")
    );
    
    graphics->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 0, -40);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(false);
    graphics->pointcloud(false);
    
    g->add(graphics);
    
    mouse = InputManager::getMouseHandle();
    
    graphics->rotation.x = 0.25;
}

EngineTest::~EngineTest () {}

void EngineTest::update(State state) {
    
    velocity.y += 0.001;
    
    if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
        velocity.y += 0.5 * mouse->getXoffset();
        graphics->scale += mouse->getYoffset() * 1.25;
    }
    
    graphics->rotation += velocity;
    velocity *= 0.8;
}
