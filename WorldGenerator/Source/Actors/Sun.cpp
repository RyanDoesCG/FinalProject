//
//  Sun.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "ModelGeometry.hpp"
#include "ShaderCache.hpp"
#include "Sun.hpp"

Sun::Sun (GraphicsEngine* g) {
    graphics = new GraphicsObject(
        new ModelGeometry ("sphere/sphere"),
        new Material      (ShaderCache::loadBasicShader("object"))
    );
    
    graphics->colour   = glm::vec4(0.5, 0.31, 0.31, 1);
    graphics->position = glm::vec3(0, 100, 0);
    graphics->scale    = glm::vec3(10, 10, 10);
    graphics->wireframe(false);
    
    g->addLight(graphics);
}

Sun::~Sun () {
    
}

void Sun::update(State state) {
    graphics->position.x += cos(glfwGetTime() * 0.001);
    graphics->position.y += sin(glfwGetTime() * 0.001);
}
