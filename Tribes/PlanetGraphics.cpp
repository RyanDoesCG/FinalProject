/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PlanetGraphics.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
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

    // BUGGY
    this->objectTransform = glm::rotate(objectTransform, 10.0f, glm::vec3(0.0, 0.0, 1.0));
    this->objectTransform = glm::scale (objectTransform, glm::vec3(0.5, 0.5, 0.5));
    // BUGGY

    this->objectTexture   = new Texture("water");
    this->objectMesh      = new Mesh(&vertices, &indices);
    
    // transform uniform to GPU
    GLuint transformLoc = glGetUniformLocation(objectShaders.at(0)->getProgramID(), "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(objectTransform));
}

PlanetGraphics::~PlanetGraphics () {

}
