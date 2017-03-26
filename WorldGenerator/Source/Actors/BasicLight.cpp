//
//  BasicLight.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "ModelGeometry.hpp"
#include "ShaderCache.hpp"
#include "BasicLight.hpp"

BasicLight::BasicLight (GraphicsEngine* g) {
    graphics = new GraphicsObject(
        new ModelGeometry ("sphere/sphere"),
        new Material      (ShaderCache::loadBasicShader("object"))
    );
    
    graphics->colour   = glm::vec4(0.5, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 30, -20);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(false);
    
    g->addLight(graphics);
}

BasicLight::~BasicLight () {
    
}

void BasicLight::update(State state) {
    graphics->position.x += cos(glfwGetTime() * 1);
    graphics->position.y += sin(glfwGetTime() * 1);
}
