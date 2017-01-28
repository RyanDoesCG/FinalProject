/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Model.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 24/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Model.hpp"
#include "../../Headers/soil/SOIL.h"
#include "../../Headers/glm/gtc/type_ptr.hpp"

void Model::setShader(string path, ProgramType type) { shader = ShaderCache::loadShaderComponent(path, type); }

void Model::loadModel(string path) {
    Assimp::Importer importer;
    
    /**
     Note on import flags:
     - aiProcess_GenNormals : actually creates normals for each vertex if the model didn’t contain normal vectors.
     
     **/
    const aiScene* scene = importer.ReadFile(path, aiProcess_GenNormals);
    
    // error check
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Assimp Error!!!!: " << importer.GetErrorString() << std::endl;
        return;
    }
    
    processNode(scene->mRootNode, scene);
    setShader("Model", BASIC);

}

void Model::processNode (aiNode* node, const aiScene* scene) {
    // process the meshes at this node
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    
    // recurse on children
    for (GLuint i = 0; i < node->mNumChildren; i++) {
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
        glm::vec3 vector; // We declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        // Positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;
        // Normals
        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.normal = vector;
        // tcww
        
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

void Model::draw (SceneCamera *camera) {
    shader->update();
    
    // Lighting data to GPU
    vec3 viewPos = camera->getPosition();
    glUniform3fv(glGetUniformLocation(shader->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));
    if (lightSource!=nullptr) {
        glm::vec3 lightPosition = lightSource->getPosition();
        glm::vec3 lightColour   = lightSource->getColour();
        
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
        glUniform3fv(glGetUniformLocation(shader->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
    }
    
    for(GLuint i = 0; i < meshes.size(); i++) {
        meshes[i].draw(shader, camera);
    }
}

void Model::update (GameState state) {
    for(GLuint i = 0; i < meshes.size(); i++) {
        meshes[i].position = this->position;
        meshes[i].rotation = this->rotation;
        meshes[i].scale    = this->scale;
        meshes[i].colour   = this->colour;
    }
}
