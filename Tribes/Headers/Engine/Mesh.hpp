#ifndef MESH_HPP
#define MESH_HPP

#include "../GLEW/glew.h"

#include "SceneCamera.hpp"
#include "ShaderComponent.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include <vector>

using namespace std;

class Mesh {
public:
    Mesh (vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
    Mesh ();
   ~Mesh ();
    
    vector<Vertex>  vertices;
    vector<GLuint>  indices;
    vector<Texture> textures;
    
    void draw (ShaderComponent* shader, SceneCamera* camera);
    void testdraw (ShaderComponent* shader, SceneCamera* camera);

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 color;
    
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    
    glm::mat4 modelTransform;
    
    // external models
    void setupModelMesh ();
    
    // quick test mesh
    vector<GLfloat> testVertices;
    void setupTestMesh  ();
};

#endif
