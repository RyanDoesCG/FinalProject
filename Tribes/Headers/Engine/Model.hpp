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
#include "ShaderComponent.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Model : public Actor {
    public:
        Model (const string& path) { this->loadModel("Assets/models/" + path + ".obj"); }
       ~Model () {}
       
        virtual void update (GameState state, SceneCamera* camera) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
    
    private:
        vector<MeshComponent> meshes;
        string directory;
    
        Actor* lightSource;
    
        void loadModel            (string path);
        void processNode          (aiNode* node, const aiScene* scene);
        MeshComponent processMesh (aiMesh* mesh, const aiScene* scene);
        ShaderComponent* shader;
    
        //vector<Texture> loadMaterialTextures (aiMaterial* mat, aiTextureType type, string typeName);
};

#endif
