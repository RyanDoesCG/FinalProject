/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Mesh.hpp"
#include "../Headers/glm/glm.hpp"
#include "../Headers/glm/gtc/type_ptr.hpp"
#include "../Headers/glm/gtc/matrix_transform.hpp"

Mesh::Mesh (vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures) {
    this->vertices = vertices;
    this->indices  = indices;
    this->textures = textures;
    
    this->setupModelMesh();
}

Mesh::Mesh (vector<GLfloat> vertices) {
    this->testVertices = vertices;
    
    this ->setupTestMesh();
}

Mesh::~Mesh () {
    glDeleteVertexArrays (1, &this->VAO);
    glDeleteBuffers      (1, &this->VBO);
    glDeleteBuffers      (1, &this->EBO);
}

void Mesh::setupTestMesh () {
    glGenVertexArrays (1, &this->VAO);
    glGenBuffers      (1, &this->VBO);
    
    glBindVertexArray (this->VAO);
    
        // Send VBO to GPU
        glBindBuffer (GL_ARRAY_BUFFER, this->VBO);
        glBufferData (GL_ARRAY_BUFFER, this->testVertices.size() * sizeof(GLfloat), &this->testVertices[0], GL_STATIC_DRAW);
    
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    
        // TexCoord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
}

void Mesh::setupModelMesh() {
    glGenVertexArrays (1, &this->VAO);
    glGenBuffers      (1, &this->VBO);
    glGenBuffers      (1, &this->EBO);
    
    glBindVertexArray (this->VAO);
    
        // Send VBO to GPU
        glBindBuffer (GL_ARRAY_BUFFER, this->VBO);
        glBufferData (GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);
    
        // send EBO to GPU
        glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData (GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
    
        // Vertex Position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    
        // Vertex Normal
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
        glEnableVertexAttribArray(1);
    
        // Vertex Texture Coordinate
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TC));
        glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);

}

void Mesh::draw(ShaderComponent* shader, SceneCamera* camera) {
    shader->update();
    
    glm::mat4 view = camera->getViewTransform();
    glm::mat4 projection = camera->getProjectionTransform();
    // send camera transforms to shader
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

/*
    // draw mesh sensible
    glBindVertexArray(VAO);
        glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(modelTransform));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
*/
    
    // draw mesh not sensible
    glBindVertexArray(VAO);
        glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
        };
    
        for (GLuint i = 0; i < 10; i++) {
            modelTransform = glm::translate(glm::mat4(), cubePositions[i]);
            GLfloat angle = 20.0f * i;
            modelTransform = glm::rotate(modelTransform, angle, glm::vec3(1.0f, 0.3f, 0.5f));
            glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(modelTransform));
        
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
    glBindVertexArray(0);
}

void Mesh::testdraw(ShaderComponent* shader, SceneCamera* camera) {
    shader->update();
    
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, (int)this->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

