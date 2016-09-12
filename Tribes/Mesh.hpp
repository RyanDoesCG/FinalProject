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

// "In C++ classes/structs are identical (in terms of initialization)."
// Structs have sequiential memory

class Mesh {
    public:
        Mesh  (std::vector<GLfloat>* vert);
        ~Mesh ();
    
        void draw(Shader shader);

    private:
        void createMesh();
    
        std::vector<GLfloat>* vertices;
        GLuint   VBO; // Vertex Buffer Object (sends verts to GPU)
};

#endif /* Mesh_hpp */
