/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"

Mesh::Mesh(GLfloat* vert) {
    
    // POTENTIAL BUG (IS THIS PROPERLY REPRESENTING THE ARRAY?!)
    
    createMesh();
}

Mesh::~Mesh() {
    
}

void Mesh::createMesh() {
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    
    glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0); // unsupported on intel
        glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Mesh::draw(Shader* shader) {
    shader->bind();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
