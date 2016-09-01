/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Mesh.hpp
 *  ShaderToy
 *
 *  Created by ryan needham on 08/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 *
 *  Needs re-writing with procedural meshes in mind as opposed
 *  to loaded in models.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Mesh_hpp
#define Mesh_hpp

#include "glm/glm.hpp"
#include "glew/glew.h"
#include "Vertex.hpp"

#include <iostream>
#include <Vector>

class IndexedModel;

class Mesh {
    public:
        // mesh from generated vertices
        Mesh (
            Vertex* vert,
            unsigned int numVertices,
            unsigned int* indices,
            unsigned int numIndices
        );
    
        // mesh from file
        Mesh  (const std::string& filename);
        ~Mesh ();
    
        void draw ();
    
    private:
        Mesh (const Mesh& other);
    
        void initMesh (const IndexedModel& model);
    
        enum {
            POSITION_VB,
            TEXTURE_VB,
            INDEX_VB,    // draw order
            NORMAL_VB,
            NUM_BUFFERS  // position in enum makes this value count elements
        };
    
        GLuint vertexArrayObject; // mesh data (OpenGL 3.0)
        GLuint vertexArrayBuffer[NUM_BUFFERS];
    
        unsigned int drawCount;
};

class IndexedModel {
    public:
        std::vector<glm::vec3> positions;
        std::vector<glm::vec2> textureCo;
        std::vector<glm::vec3> normals;
        std::vector<unsigned int> indices;
    
        void calculateNormals();
};

#endif /* Mesh_hpp */
