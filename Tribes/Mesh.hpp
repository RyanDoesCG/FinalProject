/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Mesh_hpp
#define Mesh_hpp

#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glew/GLEW.h"
#include "Shader.hpp"

#include <iostream>
#include <vector>

// look up differences between struct and class in terms of memory
struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    GLuint id;
    std::string type;
};

class Mesh {
    public:
        Mesh  (
            std::vector<Vertex>  vertices,
            std::vector<GLuint>  indices,
            std::vector<Texture> textures
        );
    
        ~Mesh ();
    
        std::vector<Vertex>  vertices;
        std::vector<GLuint>  indices;
        std::vector<Texture> textures;
    
        void draw(Shader shader);

    private:
        GLuint VAO, VBO, EBO;
        void createMesh();

};

#endif /* Mesh_hpp */
