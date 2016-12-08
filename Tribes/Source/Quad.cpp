/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Quad.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 08/12/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Quad.hpp"
#include "../Headers/Engine/ShaderCache.hpp"
#include "../Headers/glm/gtc/type_ptr.hpp"

Quad::Quad () {
    std::vector<GLfloat> vertices = {
        -0.5, 0.5, 0.0,         0.0, 0.0, 0.0,
        0.5, 0.5, 0.0,          0.0, 0.0, 0.0,
        -0.5, -0.5, 0.0,        0.0, 0.0, 0.0,
        
        -0.5, -0.5, 0.0,        0.0, 0.0, 0.0,
        0.5, -0.5, 0.0,         0.0, 0.0, 0.0,
        0.5, 0.5, 0.5,          0.0, 0.0, 0.0
    };
    
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("HUDPane", BASIC));
    mesh = (MeshComponent*)addComponent(new MeshComponent(vertices));
}

Quad::~Quad () {
    
}

void Quad::update (GameState state, SceneCamera* camera) {
    mesh->position = position;
    mesh->rotation = rotation;
    mesh->scale    = scale;
    mesh->colour   = colour;
    
    shader->update();
    
    // Lighting data to GPU
    vec3 viewPos = camera->getPosition();
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));

    mesh->testdraw(shader, camera);
}
