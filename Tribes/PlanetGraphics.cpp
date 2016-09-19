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
        /*pos*/  0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 0.0f, 0.0f, /*tc*/ 1.0f, 1.0f,
        /*pos*/  0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 1.0f, 0.0f, /*tc*/ 1.0f, 0.0f,
        /*pos*/ -0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 0.0f, 1.0f, /*tc*/ 0.0f, 0.0f,
        /*pos*/ -0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 1.0f, 0.0f, /*tc*/ 0.0f, 1.0f
    };
    
    std::vector<GLuint> indices = {
        0, 1, 2,
        0, 3, 2
    };

    this->objectShaders.push_back(new Shader("Water"));
    
    this->objectTexture = new Texture("water");
    this->objectMesh    = new Mesh(&vertices, &indices);
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    objectShaders.at(0)->bind ();
    objectTexture->bind       ();
    objectMesh->draw          ();
}
