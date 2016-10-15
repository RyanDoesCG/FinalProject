/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Mesh.hpp"
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
    
        // position
        glVertexAttribPointer     (0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray (0);
        // color
        glVertexAttribPointer     (1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray (1);
        // texture coordinates
        glVertexAttribPointer     (2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray (2);
    
    // unbind vertex array object
    glBindVertexArray(0);
    
    totalVertices = (int)vertices->size() / 3;
    
}

Mesh::Mesh (std::vector<GLfloat>* v) {
    // store vectors
    vertices = v;
    
    // convert vector to a standard array
    GLfloat vert[vertices->size()];
    for (int i = 0; i < vertices->size(); i++) vert[i] = vertices->at(i);
    
    // Set up Buffers
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    
    // bind vertex array object
    glBindVertexArray(VAO);
    
    // Bind and Buffer VERTEX ARRAY
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    
    // position
    glVertexAttribPointer     (0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray (0);
    
    // unbind vertex array object
    glBindVertexArray(0);
    
    totalVertices = (int)vertices->size() / 3;
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wire frame rendering
    glLineWidth(1.0f);
}

Mesh::~Mesh() {
    glDeleteVertexArrays (1, &VAO);
    glDeleteBuffers      (1, &VBO);
    glDeleteBuffers      (1, &EBO);
}

void Mesh::draw() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wire frame rendering
    glBindVertexArray(VAO);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, totalVertices);
    glBindVertexArray(0);
}

GLuint Mesh::getVboID() { return VBO; }
GLuint Mesh::getVaoID() { return VAO; }
GLuint Mesh::getEboID() { return EBO; }

// //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); wire frame rendering
