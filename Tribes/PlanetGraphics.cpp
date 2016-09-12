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
    std::vector<GLfloat>* vert = new std::vector<GLfloat>();
    
    vert->push_back(-0.5f);
    vert->push_back(-0.5f);
    vert->push_back(0.0f);
    
    vert->push_back(0.5f);
    vert->push_back(-0.5f);
    vert->push_back(0.0f);
    
    vert->push_back(0.0f);
    vert->push_back(0.5f);
    vert->push_back(0.0f);

    this->objectMesh   = new Mesh(vert);
    this->objectShader = new Shader("Basic");
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    this->objectMesh->draw(*objectShader);
}