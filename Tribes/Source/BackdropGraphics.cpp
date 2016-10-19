/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  BackdropGraphics.cpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/BackdropGraphics.hpp"
#include "../Headers/Engine/ShaderCache.hpp"

BackdropGraphics::BackdropGraphics  (int quality) {

    /** 
     *  Generate and scatter a collection of stars
     *  given the quality level.
     */
    for (int i = 0; i < quality; i++) {
        vertices.push_back(((rand() % 2000) / 1000.0f) - 1.0f);
        vertices.push_back(((rand() % 2000) / 1000.0f) - 1.0f);
        vertices.push_back(-1);
    }
    
    /**
     *  calculate transformation matrices
     *
     *  EXPAND ON THIS
     */
    modelMatrix      = glm::scale       (modelMatrix, glm::vec3(40.0f, 20.0f, 10.0f));
    viewMatrix       = glm::translate   (viewMatrix, glm::vec3(0.8f, 0.8f, -10.0f));
    projectionMatrix = glm::perspective (45.0f, (GLfloat)960 / (GLfloat)540, 0.1f, 100.0f);
    
    /**
     *  build a shader and a mesh
     */
    objectShaders.push_back(ShaderCache::loadShader("twinkle"));
    objectMesh = new Mesh(&vertices);
    
    /**
     *  pass transformation matrices to the shader program
     */
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"),      1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"),       1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

}

BackdropGraphics::~BackdropGraphics () {

}

void BackdropGraphics::rotateLeft () {
    viewMatrix = glm::translate (viewMatrix, glm::vec3(-0.005f, 0.0f, 0.0f));
    viewMatrix = glm::rotate    (viewMatrix, (GLfloat)0.0005, glm::vec3(0.0f, 1.0, 0.0f));
}

void BackdropGraphics::rotateRight () {
    viewMatrix = glm::translate (viewMatrix, glm::vec3(0.005f, 0.0f, 0.0f));
    viewMatrix = glm::rotate    (viewMatrix, (GLfloat)0.0005, glm::vec3(0.0f, -1.0, 0.0f));
}

void BackdropGraphics::grow () {
    viewMatrix = glm::scale (viewMatrix, glm::vec3(1.001f, 1.001f, 1.001f));
}

void BackdropGraphics::shrink () {
    viewMatrix = glm::scale (viewMatrix, glm::vec3(0.999f, 0.999f, 0.999f));
}

void BackdropGraphics::draw () {

    /** 
     *  1. Bind the shader program
     */
    objectShaders.at(0)->bind ();
    
    /** 
     *  2. Update the view matrix and upload this change
     *     to the GPU along with the time for rng
     */
    viewMatrix = glm::translate(viewMatrix, glm::vec3(-0.002f, 0.0f, 0.0f));
    glUniformMatrix4fv (glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniform1f        (glGetUniformLocation(objectShaders.at(0)->getProgramID(), "time"), glfwGetTime());
    
    /** 
     *  3.  Set draw mode and beef up points
     *      before triggering mesh.
     */
    glPolygonMode    (GL_FRONT_AND_BACK, GL_POINT);
    glPointSize      (2.0f);
    objectMesh->draw ();
}
