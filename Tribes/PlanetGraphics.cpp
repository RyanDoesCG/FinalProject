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

    GLfloat vert[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    this->objectMesh   = new Mesh();
    this->objectShader = new Shader("Basic");
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    this->objectMesh->draw(objectShader);
}
