/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  FlagGraphics.cpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/FlagGraphics.hpp"
#include "../Headers/GLM/glm.hpp"
#include <OpenGL/gl.h>
#include <vector>

FlagGraphics::FlagGraphics  () {
        glm::vec3 background = glm::vec3 (
            (rand() % 100) / 100.0f,
            (rand() % 100) / 100.0f,
            (rand() % 100) / 100.0f
        );
    
        std::vector<GLfloat> vertices = {
            /*pos*/ -0.32f, 0.32f, 0.0f, /*col*/ background.r, background.g, background.b, /*tc*/ 0.0f, 1.0f,
            /*pos*/  0.32f, 0.32f, 0.0f, /*col*/ background.r, background.g, background.b, /*tc*/ 1.0f, 1.0f,
            /*pos*/  0.32f,-0.32f, 0.0f, /*col*/ background.r, background.g, background.b, /*tc*/ 1.0f, 0.0f,
            /*pos*/ -0.32f,-0.32f, 0.0f, /*col*/ background.r, background.g, background.b, /*tc*/ 0.0f, 0.0f
         };
    
        std::vector<GLuint> indices = {
            1, 2, 3,
            1, 0, 3
        };
    
    objectShaders.push_back(new Shader("Water"));
    objectTexture.push_back(new Texture("flag"));
    objectMesh = new Mesh(&vertices, &indices);
    
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.8f, 0.8f, -0.9f));
}

FlagGraphics::~FlagGraphics () {

}

void FlagGraphics::draw() {
    objectShaders.at(0)->bind ();
    
    // Pass them to the shaders
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));   // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    
    objectTexture.at(0)->bind ();
    objectMesh->draw          ();
}
