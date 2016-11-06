/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/MeshComponent.hpp"

MeshComponent::MeshComponent (std::vector<GLfloat>* v) {
    // store vectors
    vertices = v;
    
    // convert vector to a standard array with enough
    // space for each 3 points and one index value per
    // three points
    GLfloat vert[vertices->size() + (vertices->size()/3)];
    
    for (int i = 0; i < vertices->size(); i += 3) {
        vert[i+0] = vertices->at(i+0);  // x
        vert[i+1] = vertices->at(i+1);  // y
        vert[i+2] = vertices->at(i+2);  // z
        vert[i+3] = i;                  // index
    }
    
    // Set up Buffers
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    
    // bind vertex array object
    glBindVertexArray(VAO);
    
        // Bind and Buffer VERTEX ARRAY
        glBindBuffer (GL_ARRAY_BUFFER, VBO);
        glBufferData (GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    
        // position (x, y, z)
        glVertexAttribPointer     (0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray (0);
        glVertexAttribPointer     (1, 1, GL_FLOAT, GL_FALSE, 1 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray (1);
    
    // unbind vertex array object
    glBindVertexArray(0);
    
    // House Keeping state
    totalVertices = (int)vertices->size() / 3;
}

MeshComponent::MeshComponent () {
    
}

MeshComponent::~MeshComponent () {
    glDeleteVertexArrays (1, &VAO);
    glDeleteBuffers      (1, &VBO);
    glDeleteBuffers      (1, &EBO);
}

void MeshComponent::init () {
    
}

void MeshComponent::update() {
    glBindVertexArray(VAO);

        glPointSize(8);

       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays (GL_TRIANGLES, 0, totalVertices);
    
    glBindVertexArray(0);
}
