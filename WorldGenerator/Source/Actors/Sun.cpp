//
//  Sun.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "ModelGeometry.hpp"
#include "CubeGeometry.hpp"
#include "ShaderCache.hpp"
#include "Sun.hpp"

Sun::Sun (GraphicsEngine* g) {
    graphics = new GraphicsObject(
        new ModelGeometry("sphere/sphere"),
        new Material     (ShaderCache::loadBasicShader("object"))
    );
    
    graphics->colour   = glm::vec4(0.84, 0.84, 0.84, 1);
    graphics->position = glm::vec3(0.0, 10, 0.0);
    graphics->scale    = glm::vec3(0.25, 0.25, 0.25);
    graphics->wireframe(false);
    
    g->add(graphics);
    g->addLight(graphics);
}

Sun::~Sun () {
    
}

void Sun::update(State state) {
    glClearColor(graphics->position.y * 0.05,  graphics->position.y * 0.05,  graphics->position.y * 0.05, 1.0);
    
    graphics->position.x = cos(glfwGetTime() * 0.05) * 10;
    graphics->position.y = sin(glfwGetTime() * 0.05) * 10;
}
