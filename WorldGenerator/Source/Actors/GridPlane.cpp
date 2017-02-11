//
//  GridPlane.cpp
//  WorldGenerator
//
//  Created by user on 31/01/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/GridPlane.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"
#include "../../Headers/glm/gtc/type_ptr.hpp"

GridPlane::GridPlane(float w, float h) {
    position = glm::vec3(0.0, 0.0, 0.0);
    scale    = glm::vec3(1.0, 1.0, 1.0);
    colour   = glm::vec3(0.4, 0.4, 0.4);
    
    std::vector<GLfloat> vertices = {};
    
    width = w;
    height = h;
    startX = (width / 2) * -1;
    endZ = (height / 2) * -1;
    
    float xIndex = 0;
    float zIndex = height;
    
    for (float x = startX; x < width; x += 1.0, xIndex++) {
        for (float z = height; z > endZ; z -= 1.0, zIndex--) {
            // TRIANGLE 1 VERT 1
            vertices.push_back(x - 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z + 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back(xIndex/width);       // tc u PLACEHOLDER
            vertices.push_back((zIndex-1)/height);       // tc v PLACEHOLDER
            
            // TRIANGLE 1 VERT 2
            vertices.push_back(x - 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z - 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back(xIndex/width);       // tc u PLACEHOLDER
            vertices.push_back(zIndex/height);       // tc v PLACEHOLDER
            
            // TRIANGLE 1 VERT 3
            vertices.push_back(x + 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z + 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back((xIndex+1)/width);       // tc u PLACEHOLDER
            vertices.push_back((zIndex-1)/height);       // tc v PLACEHOLDER
            
            // TRIANGLE 2 VERT 1
            vertices.push_back(x + 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z + 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back((xIndex+1)/width);       // tc u PLACEHOLDER
            vertices.push_back((zIndex-1)/height);       // tc v PLACEHOLDER
            
            // TRIANGLE 2 VERT 2
            vertices.push_back(x - 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z - 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back(xIndex/width);       // tc u PLACEHOLDER
            vertices.push_back(zIndex/height);       // tc v PLACEHOLDER
            
            // TRIANGLE 2 VERT 3
            vertices.push_back(x + 0.5);    // position x
            vertices.push_back(0.0f);       // position y
            vertices.push_back(z - 0.5);    // position z
            vertices.push_back(0.0f);       // normal x
            vertices.push_back(1.0f);       // normal y
            vertices.push_back(0.0f);       // normal z
            vertices.push_back((xIndex+1)/width);       // tc u PLACEHOLDER
            vertices.push_back(zIndex/height);       // tc v PLACEHOLDER
        }
    }
    
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("heightMapTest", BASIC));
    mesh = (MeshComponent*)addComponent(new MeshComponent(vertices));
}

GridPlane::GridPlane() {
    position = glm::vec3(0.0, 0.0, 0.0);
    scale    = glm::vec3(1.0, 1.0, 1.0);
    colour   = glm::vec3(0.4, 0.4, 0.4);
}

GridPlane::~GridPlane() {
    
}

void GridPlane::draw(SceneCamera *camera) {
    
    // Lighting data to GPU
    vec3 viewPos = camera->getPosition();
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));
    if (lightSource) {
        glm::vec3 lightPosition = lightSource->getPosition();
        glm::vec3 lightColour   = lightSource->getColour();
        
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
    }
    
    // random
    glUniform1f(glGetUniformLocation(shader->getProgramID(), "randomSeed"), rand());
    
   // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    mesh->testdraw(shader, camera);
}

void GridPlane::update(GameState state) {
    mesh->position = position;
    mesh->rotation = rotation;
    mesh->scale    = scale;
    mesh->colour   = colour;
}
