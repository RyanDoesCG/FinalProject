//
//  ModelCache.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 22/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ModelCache_hpp
#define ModelCache_hpp

#include "ModelGeometry.hpp"
#include <iostream>
#include <vector>

using namespace std;

typedef pair<vector<Vertex>, vector<GLuint>> Model;
typedef pair<string, Model> cacheEntry;

class ModelCache {
private:

public:
    static Model* loadModelGeometry (std::string path) {
        static vector<cacheEntry> cache = vector<cacheEntry>();
    
        // check the cache
        for (cacheEntry m : cache)
            if (m.first == path) return &m.second;
        
        // else load it
        Assimp::Importer loader;
        Model model;
        
        std::cout << loader.GetErrorString() << std::endl;

        const aiScene* scene = loader.ReadFile(path, aiProcess_Triangulate);
        
        // error check
        if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            std::cout << "Assimp Error!!!!: " << loader.GetErrorString() << std::endl;
        }
        
        processNode (scene->mRootNode, scene, &model);
        
        cache.push_back(cacheEntry(path, model));
        
        return &model;

    }
    
    static void processNode (aiNode* node, const aiScene* scene, Model* model) {
        // process the meshes at this node
        for (GLuint i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            processMesh(mesh, scene, model);
        }
        
        // recurse on children
        for (GLuint i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene, model);
        }
    }
    
    static void processMesh (aiMesh* mesh, const aiScene* scene, Model* model) {
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
                
                model->first.push_back(Vertex(
                    position,
                    normal,
                    uv
                ));
            }
            
            else {
               model->first.push_back(Vertex(
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
                model->second.push_back(face.mIndices[j]);
            }
        }
    }
    
};

#endif /* ModelCache_hpp */
