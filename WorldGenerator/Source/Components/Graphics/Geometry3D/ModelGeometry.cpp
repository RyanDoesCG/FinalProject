//
//  ModelGeometry.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ModelGeometry.hpp"
#include <iostream>

ModelGeometry::ModelGeometry (const std::string& path) {
    loadModel("Assets/models/" + path + ".obj");
    Geometry::setup();
}

ModelGeometry::~ModelGeometry () {}

void ModelGeometry::loadModel(std::string path) {
    Assimp::Importer loader;
    
    std::cout << loader.GetErrorString() << std::endl;
    
    const aiScene* scene = loader.ReadFile(path, aiProcess_Triangulate);
    
    // error check
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Assimp Error!!!!: " << loader.GetErrorString() << std::endl;
        return;
    }
    
    processNode (scene->mRootNode, scene);
    
}

void ModelGeometry::processNode(aiNode* node, const aiScene* scene) {
    // process the meshes at this node
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        processMesh(mesh, scene);
    }
    
    // recurse on children
    for (GLuint i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

void ModelGeometry::processMesh(aiMesh *mesh, const aiScene *scene) {
    // DEBUG
    static int processed = 0;
    processed++;
    std::cout << "Total Vertices: " << mesh->mNumVertices << std::endl;
    std::cout << "Total Faces: "    << mesh->mNumFaces    << std::endl;
    // DEBUG

    // load vertices
    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        if (mesh->mTextureCoords[0]) {
            glm::vec3 position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
            glm::vec3 normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
            glm::vec2 uv = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
            
            vertices.push_back(Vertex(
                position,
                normal,
                uv
            ));
        }
        
        else {
            vertices.push_back(Vertex(
                glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z),
                glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z),
                glm::vec2(0)
            ));
        }
    }
    
    // process indices
    for (GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (GLuint j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
}
