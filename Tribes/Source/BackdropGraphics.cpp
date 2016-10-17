/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  BackdropGraphics.cpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/BackdropGraphics.hpp"
#include "../Headers/GLEW/glew.h"
#include <vector>

BackdropGraphics::BackdropGraphics  (int quality) {
    std::vector<GLfloat> vertices = {};
    
    for (int i = 0; i < quality; i++) {
        GLfloat x = (rand() % 2000) / 1000.0f;
        GLfloat y = (rand() % 2000) / 1000.0f;
        GLfloat z = -1;
        
        x -= 1.0f;
        y -= 1.0f;
        
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
    }
    
    objectShaders.push_back(new Shader("twinkle"));
    objectMesh = new Mesh(&vertices);
    
    modelMatrix = glm::scale(modelMatrix, glm::vec3(40.0f, 20.0f, 10.0f));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.8f, 0.8f, -10.0f));
    projectionMatrix = glm::perspective(45.0f, (GLfloat)960 / (GLfloat)540, 0.1f, 100.0f);

}

BackdropGraphics::~BackdropGraphics () {

}

void BackdropGraphics::draw() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glPointSize(2.0f);
    
    objectShaders.at(0)->bind ();
    
    viewMatrix = glm::translate(viewMatrix, glm::vec3(-0.002f, 0.0f, 0.0f));
    
    // Pass them to the shaders
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    
    // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    
    glUniform1f (glGetUniformLocation(objectShaders.at(0)->getProgramID(), "time"), glfwGetTime());
    
    objectMesh->draw          ();
}

void BackdropGraphics::rotateLeft () {
    viewMatrix = glm::translate(viewMatrix, glm::vec3(-0.005f, 0.0f, 0.0f));
    viewMatrix = glm::rotate(viewMatrix, (GLfloat)0.0005, glm::vec3(0.0f, 1.0, 0.0f));
}

void BackdropGraphics::rotateRight () {
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.005f, 0.0f, 0.0f));
    viewMatrix = glm::rotate(viewMatrix, (GLfloat)0.0005, glm::vec3(0.0f, -1.0, 0.0f));
}

void BackdropGraphics::grow () {
    viewMatrix = glm::scale(viewMatrix, glm::vec3(1.001f, 1.001f, 1.001f));
}

void BackdropGraphics::shrink () {
    viewMatrix = glm::scale(viewMatrix, glm::vec3(0.999f, 0.999f, 0.999f));
}
