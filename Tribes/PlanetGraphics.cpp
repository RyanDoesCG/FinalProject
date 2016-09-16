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
        /*pos*/ -0.40f, 0.0f,  0.0f, /*col*/ 1.0f, 0.0f, 0.0f, /*tc*/ 1.0f, 1.0f,
        /*pos*/  0.0f,  0.75f, 0.0f, /*col*/ 0.0f, 1.0f, 0.0f, /*tc*/ 1.0f, 0.0f,
        /*pos*/  0.4f,  0.0f,  0.0f, /*col*/ 0.0f, 0.0f, 1.0f, /*tc*/ 0.0f, 0.0f,
        /*pos*/  0.0f, -0.75f, 0.0f, /*col*/ 1.0f, 1.0f, 0.0f, /*tc*/ 0.0f, 1.0f
    };
    
    std::vector<GLuint> indices = {
        0, 1, 2,
        0, 3, 2
    };

    this->objectShaders.push_back(new Shader("Water"));
    this->objectMesh   = new Mesh(&vertices, &indices);
}

PlanetGraphics::~PlanetGraphics () {

}

void GraphicsComponent::draw() {
    
    // water value
    GLfloat blue = (cos(glfwGetTime()) / 2) + 0.75;
    glUniform4f (
                 glGetUniformLocation(objectShaders.at(0)->programID, "proceduralColor"),
                 0.3f,
                 0.3f,
                 0.4f + (blue * 2),
                 0.5f
                 );
    
    
    objectShaders.at(0)->bind();
    glBindVertexArray(objectMesh->getVaoID());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
