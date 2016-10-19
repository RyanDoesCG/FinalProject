/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  FlagGraphics.cpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/FlagGraphics.hpp"
#include "../Headers/Engine/TextureCache.hpp"
#include "../Headers/Engine/ShaderCache.hpp"

FlagGraphics::FlagGraphics  () {
    
    /** 
     *  generate a random colour
     */
    glm::vec3 colour = glm::vec3 (
        (rand() % 100) / 100.0f,
        (rand() % 100) / 100.0f,
        (rand() % 100) / 100.0f
    );
    
    vertices = {
        // POSITION          // COLOUR                     // TEXTURE COORDINATE
        -0.32f, 0.32f, 0.0f, colour.r, colour.g, colour.b, 0.0f, 1.0f,
         0.32f, 0.32f, 0.0f, colour.r, colour.g, colour.b, 1.0f, 1.0f,
         0.32f,-0.32f, 0.0f, colour.r, colour.g, colour.b, 1.0f, 0.0f,
        -0.32f,-0.32f, 0.0f, colour.r, colour.g, colour.b, 0.0f, 0.0f
    };
    
    indices = {
        1, 2, 3,
        1, 0, 3
    };
    
    /**
     *  calculate transformation matrices
     *
     *  EXPAND ON THIS
     */
    modelMatrix      = glm::scale     (modelMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
    viewMatrix       = glm::translate (viewMatrix,  glm::vec3(0.8f, 0.8f, -0.9f));
    projectionMatrix = glm::mat4();

    /**
     *  Load an image shader, a random stencil and a mesh
     */
    objectShaders.push_back(ShaderCache::loadShader("Image"));
    objectTexture.push_back(TextureCache::loadTexture("flags/background_" + std::to_string((rand() % 13) + 1)));
    objectMesh = new Mesh(&vertices, &indices);
    
    /**
     *  pass transformation matrices to the shader program
     */
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"),      1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"),       1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

FlagGraphics::~FlagGraphics () {
    
}

void FlagGraphics::draw() {
    
    /** 
     *  1. Bind the shader program and texture
     */
    objectShaders.at(0)->bind ();
    objectTexture.at(0)->bind ();


    /** 
     *  2.  Set the draw mode and trigger the mesh
     */
    glPolygonMode    (GL_FRONT_AND_BACK, GL_FILL);
    objectMesh->draw ();
}
