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
    GLfloat vert[vertices->size()];
    
    for (int i = 0; i < vertices->size(); i++) {
        vert[i+0] = vertices->at(i+0);
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
    
    // unbind vertex array object
    glBindVertexArray(0);
    
    // House Keeping state
    totalVertices = (int)vertices->size() / 3;
}

MeshComponent::MeshComponent () {
    totalVertices = 0;
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
        glDrawArrays (GL_TRIANGLES, 0, totalVertices);
    glBindVertexArray(0);
}
