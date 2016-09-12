/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PlanetGraphics.hpp"
#include "glm/glm.hpp"

PlanetGraphics::PlanetGraphics  () {
    this->objectMesh = new Mesh(
        std::vector<Vertex>(),
        std::vector<GLuint>(),
        std::vector<Texture>()
    );
    
    this->objectShader = new Shader("Planet");
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    this->objectShader->bind();
    this->objectMesh->draw(*objectShader);
}