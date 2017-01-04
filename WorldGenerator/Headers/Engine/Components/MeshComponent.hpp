/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 15/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MeshComponent_HPP
#define MeshComponent_HPP

#include "../../GLEW/glew.h"

#include "ShaderComponent.hpp"

#include "../Actors/SceneCamera.hpp"
#include "../Utility/Texture.hpp"
#include "../Utility/Vertex.hpp"
#include <vector>

using namespace std;

class MeshComponent : public Component {
    public:
        MeshComponent (vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
        MeshComponent (vector<GLfloat> vertices, int MESSY_TEXTURE_FIX);
        MeshComponent (vector<GLfloat> vertices);
        ~MeshComponent ();
    
        vector<Vertex>  vertices;
        vector<GLuint>  indices;
        vector<Texture> textures;
    
        void draw (ShaderComponent* shader, SceneCamera* camera);
        void testdraw (ShaderComponent* shader, SceneCamera* camera);
        void texturedDraw (ShaderComponent* shader, SceneCamera* camera, GLuint texture);

        void updateModelMesh ();
        void updateTestMesh ();
        void updateTexturedMesh ();
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::vec3 colour;
    
        bool wireframe = true;
    
    private:
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
    
        glm::mat4 modelTransform;
    
        // external models
        void setupModelMeshComponent ();
    
        // quick test MeshComponent
        vector<GLfloat> testVertices;
        void setupTestMeshComponent  ();
        void setupTexturedMeshComponent ();
    
        ShaderComponent* wireframeShader;
};

#endif
