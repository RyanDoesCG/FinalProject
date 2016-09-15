/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PlanetGraphics.hpp"
#include "glm/glm.hpp"
#include <vector>

PlanetGraphics::PlanetGraphics  () {
    std::vector<GLfloat> vertices = {
         0.5f,  0.5f, 0.0f, // Top Right
         0.5f, -0.5f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f // Top Left
    };
    
    std::vector<GLuint> indices = {
        0, 1, 3, // First Triangle
        1, 2, 3    // Second Triangle
    };
    
    this->objectShader = new Shader("Basic");
    this->objectMesh   = new Mesh(&vertices, &indices);
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    this->objectMesh->draw(objectShader);
}
