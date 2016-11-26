/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MODELCOMPONENT_HPP
#define MODELCOMPONENT_HPP

#include "../assimp/Importer.hpp"
#include "../assimp/scene.h"
#include "../assimp/postprocess.h"

#include "Mesh.hpp"
#include <iostream>
#include <vector>

using namespace std;

class ModelComponent {
    public:
        ModelComponent (const string& path) {
            this->loadModel("Assets/models/" + path + ".obj");
        }
    
       ~ModelComponent () {}
    
        void draw (ShaderComponent* shader, SceneCamera* camera);
    private:
        vector<Mesh> meshes;
        string       directory;
    
        void loadModel (string path);
        void processNode (aiNode* node, const aiScene* scene);
        Mesh processMesh (aiMesh* mesh, const aiScene* scene);
    
        vector<Texture> loadMaterialTextures (aiMaterial* mat, aiTextureType type, string typeName);
        vector<Texture> textureCache;
};

#endif
