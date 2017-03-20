//
//  Butterfly.cpp
//  WorldGenerator
//
//  Created by user on 18/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Butterfly.hpp"
#include "TriGeometry.hpp"
#include "ShaderCache.hpp"
#include "Random.hpp"

Butterfly::Butterfly (GraphicsEngine* g, PhysicsEngine* p) {
    leftWing = new GraphicsObject (
        new TriGeometry(),
        new Material (ShaderCache::loadBasicShader("object"))
    );
    
    rightWing = new GraphicsObject (
        new TriGeometry(),
        new Material (ShaderCache::loadBasicShader("object"))
    );
    
    leftWing->colour = glm::vec4(1.0, 0.2, 0.2, 1.0);
    rightWing->colour = glm::vec4(1.0, 0.2, 0.2, 1.0);
    
    leftWing->rotation = glm::vec3(0.0, 0.0, 16.0);
    rightWing->rotation = glm::vec3(0.0, 0.0, -16.0);
    
    leftWing->scale = glm::vec3(1.0, 1.0, 1.0);
    rightWing->scale = glm::vec3(1.0, 1.0, 1.0);
    
    leftWing->position = glm::vec3(0.2, 4.0, 8.0);
    rightWing->position = glm::vec3(-0.2, 4.0, 8.0);
    
    leftWing->wireframe(true);
    rightWing->wireframe(true);
    
    g->add(leftWing);
    g->add(rightWing);
    
    direction = glm::vec3(0.0, 0.1, 0.0);
}

Butterfly::~Butterfly () {
    
}

void Butterfly::update (State state) {
    leftWing->rotation.y += cos(glfwGetTime()) * 0.0075;
    rightWing->rotation.y -= cos(glfwGetTime()) * 0.0075;
    
    direction += glm::vec3(betterRand(), betterRand(), betterRand());
    position += glm::normalize(direction) * glm::vec3(0.2);
    leftWing->model = glm::translate(leftWing->model, position);
    rightWing->model = glm::translate(rightWing->model, position);
}
