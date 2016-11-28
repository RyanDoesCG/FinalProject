/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/MeshComponent.hpp"
#include "../Headers/glm/glm.hpp"
#include "../Headers/glm/gtc/type_ptr.hpp"
#include "../Headers/glm/gtc/matrix_transform.hpp"

MeshComponent::MeshComponent (vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures) {
    this->vertices = vertices;
    this->indices  = indices;
    this->textures = textures;
    
    this->setupModelMeshComponent();
}

MeshComponent::MeshComponent (std::vector<GLfloat> vertices) {
    this->testVertices = vertices;
    
    this ->setupTestMeshComponent();
}

MeshComponent::~MeshComponent () {
    // Causes indexed meshes not to draw
    //glDeleteVertexArrays (1, &this->VAO);
    //glDeleteBuffers      (1, &this->VBO);
    //glDeleteBuffers      (1, &this->EBO);
}

void MeshComponent::setupTestMeshComponent () {
    glGenVertexArrays (1, &this->VAO);
    glGenBuffers      (1, &this->VBO);
    
    glBindVertexArray (this->VAO);
    
        // Send VBO to GPU
        glBindBuffer (GL_ARRAY_BUFFER, this->VBO);
        glBufferData (GL_ARRAY_BUFFER, this->testVertices.size() * sizeof(GLfloat), &this->testVertices[0], GL_STATIC_DRAW);
    
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    
        // Normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}

void MeshComponent::setupModelMeshComponent() {
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
    
        // Vertex Position (try swapping calls)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    
        // Vertex Normal
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
        glEnableVertexAttribArray(1);
    
        // Vertex Texture Coordinate
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, tc));
        glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);

}

void MeshComponent::draw(ShaderComponent* shader, SceneCamera* camera) {
    
    // upload colour to shader
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "objectColour"), 1, glm::value_ptr(colour));
    
    // Give camera transforms to shader
    glm::mat4 view = camera->getViewTransform();
    glm::mat4 projection = camera->getProjectionTransform();
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    // Give model transform to shader
    modelTransform = glm::translate(glm::mat4(), position);
    modelTransform = glm::scale(modelTransform, scale);
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(modelTransform));
    
    // Draw that bitch
    glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void MeshComponent::testdraw(ShaderComponent* shader, SceneCamera* camera) {
    
    // upload colour to shader
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "objectColour"), 1, glm::value_ptr(colour));
    
    // Give camera transforms to shader
    glm::mat4 view = camera->getViewTransform();
    glm::mat4 projection = camera->getProjectionTransform();
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    // Give model transform to shader
    modelTransform = glm::translate(glm::mat4(), position);
    modelTransform = glm::scale(modelTransform, scale);
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(modelTransform));
    
    // render
    glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

