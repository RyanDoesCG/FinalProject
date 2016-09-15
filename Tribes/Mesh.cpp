/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"

// 863422310

Mesh::Mesh(std::vector<GLfloat>* v, std::vector<GLuint>* i) {
    // store vectors
    vertices = v;
    indices  = i;
    
    // convert vector to a standard array
    GLfloat vert[vertices->size()];
    GLuint  indi[indices->size()];
    for (int i = 0; i < vertices->size(); i++) vert[i] = vertices->at(i);
    for (int i = 0; i < indices->size(); i++)  indi[i] = indices->at(i);
    
    // Set up Buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // bind vertex array object
    glBindVertexArray(VAO);
        // Vertices to GPU Buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    
        // Indices to GPU Buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indi), indi, GL_STATIC_DRAW);
    
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays (1, &VAO);
    glDeleteBuffers      (1, &VBO);
    glDeleteBuffers      (1, &EBO);
}

void Mesh::draw(Shader* shader) {
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader->bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
