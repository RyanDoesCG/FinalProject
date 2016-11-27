/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Model_HPP
#define Model_HPP

#include "../assimp/Importer.hpp"
#include "../assimp/scene.h"
#include "../assimp/postprocess.h"

#include "MeshComponent.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Model : Actor {
    public:
        Model (const string& path) {
            this->loadModel("Assets/models/" + path + ".obj");
        }
    
       ~Model () {}
    
        void draw (ShaderComponent* shader, SceneCamera* camera);
    private:
        vector<MeshComponent> MeshComponentes;
        string       directory;
    
        void loadModel (string path);
        void processNode (aiNode* node, const aiScene* scene);
        MeshComponent processMesh (aiMesh* mesh, const aiScene* scene);
    
        vector<Texture> loadMaterialTextures (aiMaterial* mat, aiTextureType type, string typeName);
        vector<Texture> textureCache;
};

#endif
