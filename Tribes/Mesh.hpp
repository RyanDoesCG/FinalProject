/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
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

// "In C++ classes/structs are identical (in terms of initialization)."
// Structs have sequiential memory

class Mesh {
    public:
        Mesh  (std::vector<GLfloat>* v, std::vector<GLuint>* i);
        ~Mesh ();
    
        void draw(Shader* shader);

    private:
        // ideally this should be a C array but had issues passing.
        std::vector<GLfloat>* vertices;
        std::vector<GLuint>*  indices;
    
        GLuint VBO; // Vertex Buffer Object (sends verts to GPU)
        GLuint VAO; // Vertex Array Object
        GLuint EBO; // Element Buffer Object
};

#endif /* Mesh_hpp */
