/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Model.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Model_hpp
#define Model_hpp

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
        Model () {}
       ~Model () {}
       
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
        void setShader      (string path, ProgramType type);
        ShaderComponent* getShader () {return shader;}
    
        vector<MeshComponent> meshes;
        Actor* lightSource;
    
    protected:
        string directory;
    
        void loadModel            (string path);
        void processNode          (aiNode* node, const aiScene* scene);
        MeshComponent processMesh (aiMesh* mesh, const aiScene* scene);
        ShaderComponent* shader;
    
        //vector<Texture> loadMaterialTextures (aiMaterial* mat, aiTextureType type, string typeName);
};

#endif
