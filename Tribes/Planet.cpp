/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Planet.hpp"

Planet::Planet  () {
    this->waterShader = new Shader("water");
    this->landShader = new Shader("land");
    generatePlanet();
}

Planet::~Planet () {
    free(planetMesh);
    free(waterShader);
    free(landShader);
}

//      /\
//     /  \
//     \  /
//      \/

void Planet::generatePlanet () {
    // make an octohedron mesh
    GLuint indices[] = {
        0,
        1,
        2,
        3
    };

    // build a triangle
    Vertex vert[] = {
        Vertex(glm::vec3(20, 40, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0)),
        Vertex(glm::vec3(40, 80, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0)),
        Vertex(glm::vec3(60, 40, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0)),
        Vertex(glm::vec3(40,  0, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0))
    };
    
    this->planetMesh = new Mesh(vert, 4, indices, 4);
    
}

void Planet::render() {
    waterShader->bind();
    planetMesh->draw();
}

