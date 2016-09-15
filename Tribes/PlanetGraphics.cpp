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
        -0.40f, 0.0f, 0.0f,
        0.0f, 0.75f, 0.0f,
        0.40f, 0.0f, 0.0f,
        0.0f, -0.75f, 0.0f
    };
    
    std::vector<GLuint> indices = {
        0, 1, 2,
        0, 3, 2
    };
    
    this->objectShader = new Shader("Basic");
    this->objectMesh   = new Mesh(&vertices, &indices);
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    this->objectMesh->draw(objectShader);
}
