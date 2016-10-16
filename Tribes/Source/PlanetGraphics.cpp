/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/PlanetGraphics.hpp"
#include "../Headers/Engine/MathsToolkit.hpp"
#include <vector>

PlanetGraphics::PlanetGraphics  () {

    // octohedron
    std::vector<GLfloat> vertices = {
        // 1
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.5f,
        
        // 2
        -0.5, 0.0f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.0f, -0.5, 0.0f,
        
        // 3
        0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.5f,
        
        // 4
        0.0f, -0.5f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.5f, 0.00f, 0.0f,
        
        // 5
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, -0.5f,
        
        // 6
        -0.5, 0.0f, 0.0f,
        0.0f, -0.5, 0.0f,
        0.0f, 0.0f, -0.5f,
        
        
        // 7
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, -0.5f,
        0.5f, 0.0f, 0.0f,
        
        // 8
        0.0f, 0.0f, -0.5f,
        0.5f, 0.00f, 0.0f,
        0.0f, -0.5f, 0.0f,
    };
    
    MathsToolkit::parseOctohedron(&vertices, 4);
    MathsToolkit::normalizeOctohedron(&vertices, 1.8); // broken
    
    modelMatrix = glm::rotate(modelMatrix, (GLfloat)0.08, glm::vec3(1.0f, 0.0f, 0.0f));
    viewMatrix  = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    projectionMatrix = glm::perspective(45.0f, (GLfloat)960 / (GLfloat)540, 0.1f, 100.0f);
    
    objectShaders.push_back(new Shader("Water"));
    objectTexture.push_back(new Texture("flags/background_1"));
    objectMesh = new Mesh(&vertices);

}

PlanetGraphics::~PlanetGraphics () {

}

void PlanetGraphics::draw() {
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    objectShaders.at(0)->bind ();
    
    // calculate transformations
    modelMatrix      = glm::rotate(modelMatrix, (GLfloat)0.002, glm::vec3(0.0f, 1.0f, 0.0f));
    
    // Pass them to the shaders
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));   // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    
    objectTexture.at(0)->bind ();
    objectMesh->draw          ();
}

//    std::vector<GLfloat> vertices = {
//        /*pos*/  0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 0.0f, 0.0f, /*tc*/ 1.0f, 1.0f,
//        /*pos*/  0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 1.0f, 0.0f, /*tc*/ 1.0f, 0.0f,
//        /*pos*/ -0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 0.0f, 1.0f, /*tc*/ 0.0f, 0.0f,
//        /*pos*/ -0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 1.0f, 0.0f, /*tc*/ 0.0f, 1.0f
//     };

//    std::vector<GLuint> indices = {
//        0, 1, 2,
//        0, 3, 2
//    };

/*
 // cube
 std::vector<GLfloat> vertices = {
 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
 
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
 -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 
 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
 };
 */
