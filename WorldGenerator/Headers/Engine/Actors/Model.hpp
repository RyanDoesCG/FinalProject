/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Model.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Model_HPP
#define Model_HPP

#include "../../assimp/Importer.hpp"
#include "../../assimp/scene.h"
#include "../../assimp/postprocess.h"

#include "../Components/MeshComponent.hpp"
#include "../Utility/ShaderCache.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Model : public Actor {
    public:
        Model (const string& path) { this->loadModel("Assets/models/" + path + ".obj"); }
       ~Model () {}
       
        virtual void update (GameState state, SceneCamera* camera) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
        void setShader      (string path, ProgramType type);
        ShaderComponent* getShader () {return shader;}
    
        vector<MeshComponent> meshes;
    
    protected:
        string directory;
    
        Actor* lightSource;
    
        void loadModel            (string path);
        void processNode          (aiNode* node, const aiScene* scene);
        MeshComponent processMesh (aiMesh* mesh, const aiScene* scene);
        ShaderComponent* shader;
    
        //vector<Texture> loadMaterialTextures (aiMaterial* mat, aiTextureType type, string typeName);
};

#endif
