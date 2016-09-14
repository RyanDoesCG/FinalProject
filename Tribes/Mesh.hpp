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
        Mesh  ();
        ~Mesh ();
    
        void draw(Shader* shader);

    private:
        void createMesh();

        // STORE VERTICES IN A MANNER THAT CAN BE PASSED/STORED EASILY BETWEEN CLASSES
    
        GLuint   VBO; // Vertex Buffer Object (sends verts to GPU)
        GLuint   VAO; // Vertex Array Object
};

#endif /* Mesh_hpp */
