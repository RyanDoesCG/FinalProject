/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.cpp
 *  ShaderToy
 *
 *  Created by ryan needham on 08/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Mesh.hpp"
#include <vector>

/** 
 *  Mesh Constructor
 *
 *  @param vert         A pointer to an array of vertices
 *  @param numVertices  The number of vertices in the array
 *
 *  takes a pointer to a vertx array and the size of
 *  said array. Generates and binds a vertex array to
 *  the GL context, sends it to the GPU and enables it.
 */
Mesh::Mesh (Vertex* vert, unsigned int numVertices, unsigned int* indices, unsigned int numIndices) {
    IndexedModel model;
    
    for (unsigned int i = 0; i < numVertices; i++) {
        model.positions.push_back(*vert[i].getPositionCoordinates() );
        model.textureCo.push_back(*vert[i].getTextureCoordinates());
        model.normals.push_back(*vert[i].getNormal());
    }
    
    for (unsigned int i = 0; i < numIndices; i++) {
        model.indices.push_back(indices[i]);
    }
    
    initMesh(model);
 
}

/**
 *  Mesh Constructor
 *
 *  @param filename     The location of the .obj model to be loaded
 *
 *  takes a pointer to a vertx array and the size of
 *  said array. Generates and binds a vertex array to
 *  the GL context, sends it to the GPU and enables it.
 */
Mesh::Mesh (const std::string& filename) {
//    IndexedModel model = OBJModel(filename).ToIndexedModel();
//    initMesh(model);
}

/** 
 *  Mesh Destructor
 *  
 *  Deletes the vertex array
 */
Mesh::~Mesh () {
    glDeleteVertexArrays (1, &vertexArrayObject); // MAYBE ISSUE
}

/** 
 *  initMesh
 *
 *  @param model    The address of the model in memory
 *
 *  
 */
void Mesh::initMesh(const IndexedModel& model) {
    drawCount = (int)model.indices.size();

    // generate vertex array
    glGenVertexArrays (1, &vertexArrayObject);
    glBindVertexArray (vertexArrayObject);

    // generate and bind vertex buffer
    glGenBuffers (NUM_BUFFERS, vertexArrayBuffer);
    
    /* POSITION */
    glBindBuffer (GL_ARRAY_BUFFER, vertexArrayBuffer[POSITION_VB]);
    glBufferData (
        GL_ARRAY_BUFFER,
        model.positions.size() * sizeof(model.positions[0]),
        &model.positions[0],
        GL_STATIC_DRAW
    ); // to VRAM
    
    // attribute array and pointer
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    /* TEXTURE COORDINATES */
    glBindBuffer (GL_ARRAY_BUFFER, vertexArrayBuffer[TEXTURE_VB]);
    glBufferData (
        GL_ARRAY_BUFFER,
        model.positions.size() * sizeof(model.textureCo[0]),
        &model.textureCo[0],
        GL_STATIC_DRAW
    ); // to VRAM
    
    // attribute array and pointer
    glEnableVertexAttribArray (1);
    glVertexAttribPointer (1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    /* NORMALS */
    glBindBuffer (GL_ARRAY_BUFFER, vertexArrayBuffer[NORMAL_VB]);
    glBufferData (
        GL_ARRAY_BUFFER,
        model.normals.size() * sizeof(model.normals[0]),
        &model.normals[0],
        GL_STATIC_DRAW
    ); // to VRAM
    
    // attribute array and pointer
    glEnableVertexAttribArray (2);
    glVertexAttribPointer (2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    /* INDEX */
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffer[INDEX_VB]);
    glBufferData (
        GL_ELEMENT_ARRAY_BUFFER,
        model.indices.size() * sizeof(model.indices[0]),
        &model.indices[0],
        GL_STATIC_DRAW
    ); // to VRAM
    
    // attribute array and pointer
    glEnableVertexAttribArray (3);
    glVertexAttribPointer (3, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    // unbind both
    glBindVertexArray (0);
}

/** 
 *  draw
 *
 *  binds the vertex array and draws it as triangles
 *  before unbinding.
 */
void Mesh::draw () {
    // bind
    glBindVertexArray (vertexArrayObject);
    
    // draw
    glDrawElements (GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
    
    // unbind
    glBindVertexArray (0);
}

void IndexedModel::calculateNormals() {
    for(unsigned int i = 0; i < indices.size(); i += 3) {
        int i0 = indices[i];
        int i1 = indices[i + 1];
        int i2 = indices[i + 2];
        
        glm::vec3 v1 = positions[i1] - positions[i0];
        glm::vec3 v2 = positions[i2] - positions[i0];
        
        glm::vec3 normal = glm::normalize(glm::cross(v1, v2));
        
        normals[i0] += normal;
        normals[i1] += normal;
        normals[i2] += normal;
    }
    
    for(unsigned int i = 0; i < positions.size(); i++)
        normals[i] = glm::normalize(normals[i]);
}

/*
 // Create a test mesh
 Vertex vert[] = {
 Vertex(glm::vec3(-0.3, -0.5, 0), glm::vec2(0.0, 0.0)),
 Vertex(glm::vec3(0, 0.3, 0),     glm::vec2(0.5, 1.0)),
 Vertex(glm::vec3(0.3, -0.5, 0),  glm::vec2(1.0, 0.0))
 };
*/
