//
//  Triangle.cpp
//  WorldGenerator
//
//  Created by user on 15/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/Triangle.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"
#include "../../Headers/glm/gtc/type_ptr.hpp"

void Triangle::setShader(string path, ProgramType type) { shader = ShaderCache::loadShaderComponent(path, type); }


Triangle::Triangle() {
    position = glm::vec3(0.0, 0.0, 0.0);
    scale    = glm::vec3(1.0, 1.0, 1.0);
    colour   = glm::vec3(0.4, 0.4, 0.4);
    
    
    /**
     *  LAYOUT:
     *     - position (x, y, z)
     *     - normal   (x, y, z)
     *     - tc       (u, v)
     */
    std::vector<GLfloat> vertices = {
        -0.5, 0.0, 0.0,     0.0, 0.0, 0.0,      0, 0,
        0.0, 0.5, 0.0,      0.0, 0.0, 0.0,      0, 0,
        0.5, 0.0, 0.0,      0.0, 0.0, 0.0,      0, 0
    };
    
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("litObject", BASIC));
    mesh   = (MeshComponent*)addComponent(new MeshComponent(vertices));
}

Triangle::~Triangle() {
    
}

void Triangle::draw (SceneCamera* camera) {
    shader->update();
    
    // Lighting data to GPU
    vec3 viewPos = camera->getPosition();
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));
    if (lightSource != nullptr) {
        glm::vec3 lightPosition = lightSource->getPosition();
        glm::vec3 lightColour   = lightSource->getColour();
        
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
    }
    
    mesh->testdraw(shader, camera);
}

void Triangle::update (GameState state) {
    mesh->position = position;
    mesh->rotation = rotation;
    mesh->scale    = scale;
    mesh->colour   = colour;
}

