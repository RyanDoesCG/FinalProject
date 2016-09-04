/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PlanetGraphics.hpp"

//   /\
//  /  \
//  \  /
//   \/

PlanetGraphics::PlanetGraphics  () {
    this->mesh = new Mesh("Assets/models/CompCube.obj");
    this->shader = new Shader("land");
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::render() {
    shader->bind();
    mesh->draw();
}
