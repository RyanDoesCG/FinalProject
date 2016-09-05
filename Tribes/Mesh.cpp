/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"

Mesh::Mesh  (std::vector<Vertex>  vertices,
             std::vector<GLuint>  indices,
             std::vector<Texture> textures) {
    this->vertices = vertices;
    this->indices  = indices;
    this->textures = textures;
    
    createMesh();
}

Mesh::~Mesh () {

}

void Mesh::createMesh() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);
  
    glBindVertexArray(this->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), 
                 &this->vertices[0], GL_STATIC_DRAW);  

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), 
                 &this->indices[0], GL_STATIC_DRAW);

    // Vertex Positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                         (GLvoid*)0);
    // Vertex Normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                         (GLvoid*)offsetof(Vertex, Normal));
    // Vertex Texture Coords
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                         (GLvoid*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);
}

void Mesh::draw(Shader shader) {
    shader.bind();
    glUniform1f(glGetUniformLocation(shader.uniforms[0], "position"), 0);
    glUniform1f(glGetUniformLocation(shader.uniforms[0], "normal"), 0);
    glUniform1f(glGetUniformLocation(shader.uniforms[0], "textureCoordinates"), 0);
    
    
    // Draw mesh
    glBindVertexArray(this->VAO);
    
    glDrawElements(
        GL_TRIANGLES,
        (int)this->indices.size(),
        GL_UNSIGNED_INT,
        0
    );
    
    glBindVertexArray(0);
}
