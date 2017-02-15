//
//  Pyramid.cpp
//  WorldGenerator
//
//  Created by user on 15/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/Pyramid.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Pyramid.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 27/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Pyramid.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"
#include "../../Headers/glm/gtc/type_ptr.hpp"

void Pyramid::setShader(string path, ProgramType type) { shader = ShaderCache::loadShaderComponent(path, type); }


Pyramid::Pyramid() {
    position = glm::vec3(0.0, 0.0, 0.0);
    scale    = glm::vec3(1.0, 1.0, 1.0);
    colour   = glm::vec3(0.4, 0.4, 0.4);
    
    
    /**
     *  LAYOUT:
     *     - position (x, y, z)
     *     - normal   (x, y, z)
     *     - tc       (u, v) (NOT REAL)
     */
    std::vector<GLfloat> vertices = {
        0.5, -0.5, -0.5,   1.0, 0.0, 0.0,    0, 0, 0,     0.0,  0.5, -0.0,   1.0, 0.0, 0.0,   0, 0, 0,   0.5, -0.5,  0.5,   1.0, 0.0, 0.0,  0, 0, 0,
        0.5, -0.5,  0.5,   1.0, 0.0, 0.0,    0, 0, 0,     0.0,  0.5, -0.0,   1.0, 0.0, 0.0,   0, 0, 0,   0.0,  0.5,  0.0,   1.0, 0.0, 0.0,  0, 0, 0,
        0.0, 0.5, -0.0,    0.0, 1.0, 0.0,    0, 0, 0,     -0.0, 0.5, -0.0,   0.0, 1.0, 0.0,   0, 0, 0,   0.0, 0.5,  0.0,    0.0, 1.0, 0.0,  0, 0, 0,
        0.0, 0.5,  0.0,    0.0, 1.0, 0.0,    0, 0, 0,     -0.0, 0.5, -0.0,   0.0, 1.0, 0.0,   0, 0, 0,   -0.0, 0.5,  0.0,   0.0, 1.0, 0.0,  0, 0, 0,
        -0.0,  0.5, -0.0,  -1.0, 0.0, 0.0,   0, 0, 0,     -0.5, -0.5, -0.5,  -1.0, 0.0, 0.0,  0, 0, 0,   -0.0,  0.5,  0.0,  -1.0, 0.0, 0.0, 0, 0, 0,
        -0.0,  0.5,  0.0,  -1.0, 0.0, 0.0,   0, 0, 0,     -0.5, -0.5, -0.5,  -1.0, 0.0, 0.0,  0, 0, 0,   -0.5, -0.5,  0.5,  -1.0, 0.0, 0.0, 0, 0, 0,
        -0.5, -0.5, -0.5,   0.0, -1.0, 0.0,  0, 0, 0,    0.5, -0.5, -0.5,   0.0, -1.0, 0.0,   0, 0, 0,   -0.5, -0.5,  0.5,  0.0, -1.0, 0.0, 0, 0, 0,
        -0.5, -0.5,  0.5,   0.0, -1.0, 0.0,  0, 0, 0,    0.5, -0.5, -0.5,   0.0, -1.0, 0.0,   0, 0, 0,   0.5, -0.5,  0.5,   0.0, -1.0, 0.0, 0, 0, 0,
        0.0,  0.5, 0.0,     0.0, 0.0, 1.0,   0, 0, 0,    -0.0,  0.5, 0.0,    0.0, 0.0, 1.0,   0, 0, 0,   0.5, -0.5, 0.5,    0.0, 0.0, 1.0,  0, 0, 0,
        0.5, -0.5, 0.5,     0.0, 0.0, 1.0,   0, 0, 0,    -0.0,  0.5, 0.0,    0.0, 0.0, 1.0,   0, 0, 0,   -0.5, -0.5, 0.5,    0.0, 0.0, 1.0, 0, 0, 0,
        0.5, -0.5, -0.5,    0.0, 0.0, -1.0,  0, 0, 0,    -0.5, -0.5, -0.5,   0.0, 0.0, -1.0,  0, 0, 0,   0.0,  0.5, -0.0,   0.0, 0.0, -1.0, 0, 0, 0,
        0.0,  0.5, -0.0,    0.0, 0.0, -1.0,  0, 0, 0,    -0.5, -0.5, -0.5,   0.0, 0.0, -1.0,  0, 0, 0,   -0.0,  0.5, -0.0,   0.0, 0.0, -1.0, 0, 0, 0
    };
    
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("litObject", BASIC));
    mesh   = (MeshComponent*)addComponent(new MeshComponent(vertices));
}

Pyramid::~Pyramid() {
    
}

void Pyramid::draw (SceneCamera* camera) {
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

void Pyramid::update (GameState state) {
    mesh->position = position;
    mesh->rotation = rotation;
    mesh->scale    = scale;
    mesh->colour   = colour;
}
