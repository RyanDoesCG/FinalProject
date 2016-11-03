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
#include "../Headers/Engine/ShaderCache.hpp"

PlanetGraphics::PlanetGraphics  () {

    /** 
     *  Build basic vertex collection.
     *
     *      /\
     *     /  \
     *     \  /
     *      \/
     */
    vertices = {
    // x      y      z     biome x      y      z     biome x      y      z     biome
      -0.5f,  0.0f,  0.0f, 1.0f, 0.0f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.5f, 1.0f, // TRIANGLE 1
      -0.5f,  0.0f,  0.0f, 2.0f, 0.0f,  0.0f,  0.5f, 2.0f, 0.0f, -0.5f,  0.0f, 2.0f, // TRIANGLE 2
       0.5f,  0.0f,  0.0f, 3.0f, 0.0f,  0.5f,  0.0f, 3.0f, 0.0f,  0.0f,  0.5f, 3.0f, // TRIANGLE 3
       0.0f, -0.5f,  0.0f, 4.0f, 0.0f,  0.0f,  0.5f, 4.0f, 0.5f,  0.0f,  0.0f, 4.0f, // TRIANGLE 4
      -0.5f,  0.0f,  0.0f, 1.0f, 0.0f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -0.5f, 1.0f, // TRIANGLE 5
      -0.5f,  0.0f,  0.0f, 2.0f, 0.0f, -0.5f,  0.0f, 2.0f, 0.0f,  0.0f, -0.5f, 2.0f, // TRIANGLE 6
       0.0f,  0.5f,  0.0f, 3.0f, 0.0f,  0.0f, -0.5f, 3.0f, 0.5f,  0.0f,  0.0f, 3.0f, // TRIANGLE 7
       0.0f,  0.0f, -0.5f, 4.0f, 0.5f,  0.0f,  0.0f, 4.0f, 0.0f, -0.5f,  0.0f, 4.0f, // TRIANGLE 8
    };
    
    /** 
     *  Parse the octohedron into a pseudo-sphere
     *
     */
    MathsToolkit::parseOctohedron     (&vertices, 3); // REWRITE
    MathsToolkit::normalizeOctohedron (&vertices, 1.02);
    
    /**
     *  calculate transformation matrices
     *  
     *  EXPAND ON THIS
     */
    modelMatrix      = glm::rotate      (modelMatrix, (GLfloat)0.00, glm::vec3(0.0f, 1.0f, 0.0f)); // kick/tilt back
    modelMatrix      = glm::scale       (modelMatrix, glm::vec3(0.5, 0.5, 0.1));
    viewMatrix       = glm::translate   (viewMatrix,  glm::vec3(0.0f, 0.0f, -3.0f));
    projectionMatrix = glm::perspective (45.0f,       (GLfloat)960 / (GLfloat)540, 0.1f, 100.0f);
    
    /** 
     *  build a shader and a mesh
     */
    objectShaders.push_back(ShaderCache::loadShader("BasicBlack"));
    objectMesh = new Mesh(&vertices);
    
    /** 
     *  pass transformation matrices to the shader program
     */
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"),      1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"),       1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

}

PlanetGraphics::~PlanetGraphics () {

}

void PlanetGraphics::draw() {

    /**
     *  1. bind the shader program. This class has
     *     no texture to bind so skip that.
     */
    objectShaders.at(0)->bind ();

    /**
     *  2. Rotate the planet model slightly every frame and
     *     pass this update to the GPU via a shader program.
     */
    modelMatrix = glm::rotate(modelMatrix, (GLfloat)0.002, glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Send mouse position to GPU
    glUniform3fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "mousePos"), 1, glm::value_ptr(mousePos));
    
    /** 
     *  3. Set the polygon draw mode (GL_FILL for release,
     *     GL_LINE for debug, GL_POINT for art) and trigger
     *     the mesh to render.
     */
    glPolygonMode    (GL_FRONT_AND_BACK, GL_LINE);
    objectMesh->draw ();

}
