#ifndef MeshComponent_HPP
#define MeshComponent_HPP

#include "../GLEW/glew.h"

#include "SceneCamera.hpp"
#include "ShaderComponent.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include <vector>

using namespace std;

class MeshComponent : public ActorComponent {
    public:
        MeshComponent (vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
        MeshComponent (vector<GLfloat> vertices);
        ~MeshComponent ();
    
        vector<Vertex>  vertices;
        vector<GLuint>  indices;
        vector<Texture> textures;
    
        void draw (ShaderComponent* shader, SceneCamera* camera);
        void testdraw (ShaderComponent* shader, SceneCamera* camera);

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
    
        ShaderComponent* wireframeShader;
};

#endif
