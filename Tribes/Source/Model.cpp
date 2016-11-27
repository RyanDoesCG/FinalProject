/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Model.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 24/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
    Note on import flags:
        - aiProcess_GenNormals : actually creates normals for each vertex if the model didn’t contain normal vectors.
 
 **/
#include "../Headers/Engine/Model.hpp"
#include "../Headers/soil/SOIL.h"

void Model::loadModel(string path) {
    Assimp::Importer importer;
    
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);
    
    // error check
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Assimp Error!!!!: " << importer.GetErrorString() << std::endl;
        return;
    }
    
    processNode(scene->mRootNode, scene);
}

void Model::processNode (aiNode* node, const aiScene* scene) {
    // process the meshes at this node
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    
    // recurse on children
    for (GLuint i = 1; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

MeshComponent Model::processMesh (aiMesh* mesh, const aiScene* scene) {
    // DEBUG
    static int processed = 0;
    processed++;
    cout << "Total Vertices: " << mesh->mNumVertices << endl;
    cout << "Total Faces: " << mesh->mNumFaces << endl;
    // DEBUG
    
    vector<Vertex>  vertices;
    vector<GLuint>  indices;
    vector<Texture> textures;
    
    // process vertices
    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        // position
        vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;
        // normal
        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.Normal = vector;
        // tc (skip)
        vertices.push_back(vertex);
    }
    
    // process indices
    for (GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (GLuint j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
    
    // materials (skip for now)

    
    return MeshComponent(vertices, indices, textures);
}


void Model::draw(ShaderComponent* shader, SceneCamera* camera) {
    
}
