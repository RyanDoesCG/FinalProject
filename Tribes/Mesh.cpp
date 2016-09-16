/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"
#include <math.h>

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
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    glGenBuffers      (1, &EBO);

    // bind vertex array object
    glBindVertexArray(VAO);
        // Bind and Buffer VERTEX ARRAY
        glBindBuffer (GL_ARRAY_BUFFER, VBO);
        glBufferData (GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    
        // Bind and Buffer ELEMENT ARRAY
        glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof(indi), indi, GL_STATIC_DRAW);
    
        // Enable VERTEX ATTRIBUTE ARRAY
        glVertexAttribPointer     (2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat)));
        glEnableVertexAttribArray (2);
    
        // unbind vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    // unbind vertex array object
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays (1, &VAO);
    glDeleteBuffers      (1, &VBO);
    glDeleteBuffers      (1, &EBO);
}

void Mesh::draw(std::vector<Shader*>* shader) {

}

GLuint Mesh::getVboID() {return VBO;}
GLuint Mesh::getVaoID() {return VAO;}
GLuint Mesh::getEboID() {return EBO;}

// //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); wire frame rendering
