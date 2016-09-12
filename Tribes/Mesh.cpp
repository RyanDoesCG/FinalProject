/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"

Mesh::Mesh(std::vector<GLfloat>* vert) {
    this->vertices = vert;
    createMesh();
}

Mesh::~Mesh() {
    
}

void Mesh::createMesh() {
    glGenBuffers (1, &VBO);
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );
    
}

void Mesh::draw(Shader shader) {

}
