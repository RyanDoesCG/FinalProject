//
//  Geometry.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include <iostream>
#include "Geometry.hpp"

Geometry::Geometry() {
    position = glm::vec3(0, 0, 0);
    rotation = glm::vec3(0);
    scale    = glm::vec3(1);
    
    wireframe = false;
    
    setup();
}

Geometry::~Geometry() {

}

void Geometry::setup() {
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    glGenBuffers      (1, &EBO);
    
    glBindVertexArray(VAO);
    
    // Send VBO to GPU
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);
    
    // send EBO to GPU
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
    
    // Vertex Position (try swapping calls)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    // Vertex Normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    
    // Vertex uvs
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    //for (int i = 0; i < vertices.size(); i++) std::cout << vertices.at(i).string() << ", " << std::endl;
}

void Geometry::render() {
    glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
