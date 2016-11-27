/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ModelComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 24/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/ModelComponent.hpp"
#include "../Headers/soil/SOIL.h"

GLint TextureFromFile(const char* path, string directory);

void ModelComponent::draw(ShaderComponent* shader, SceneCamera* camera) {
    
}

void ModelComponent::loadModel(string path) {

}

void ModelComponent::processNode (aiNode* node, const aiScene* scene) {\

}

Mesh ModelComponent::processMesh (aiMesh* mesh, const aiScene* scene) {
    static int processed = 0;
    processed++;
    cout << "Total Vertices: " << mesh->mNumVertices << endl;
    cout << "Total Faces: " << mesh->mNumFaces << endl;
    
    vector<Vertex>  vertices;
    vector<GLuint>  indices;
    vector<Texture> textures;
    

    
    return Mesh(vertices, indices, textures);
}

vector<Texture> ModelComponent::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName) {
    vector<Texture> textures;

    return textures;
}

GLint TextureFromFile(const char* path, string directory) {
    GLuint textureID = 0;
    
    return textureID;
}
