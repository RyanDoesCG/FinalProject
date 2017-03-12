//
//  PlaneGeometry.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "PlaneGeometry.hpp"

PlaneGeometry::PlaneGeometry (const int size) {
    vertices = {};
    indices  = {};
    
    // TEST
    std::vector<glm::vec3> verts;
    std::vector<GLuint> ind;
    
    const int WIDTH = size;
    const int DEPTH = size;
    const int HALF_WIDTH = WIDTH >> 1;
    const int HALF_DEPTH = DEPTH >> 1;
    
    const int VERT_COUNT = WIDTH * DEPTH;
    const int IND_COUNT  = VERT_COUNT * 2 * 3;
    
    //fill indices array
    GLuint* id = &ind[0];
    
    //setup vertices
    int count = 0;
    
    //fill terrain vertices
    for(int z = 0; z < DEPTH; z++) {
        
        for(int x = 0; x < WIDTH; x++, count++) {
            
            verts[count] = glm::vec3(
                (float(x)/(WIDTH-1)),
                0,
                (float(z)/(DEPTH-1))
            );
        }
    }
    
        //fill terrain indices
    for (int z = 0; z < DEPTH - 1; z++) {
        for (int x = 0; x < WIDTH-1; x++) {
            int i0 = x + z * WIDTH;
            int i1 = i0+1;
            int i2 = i0+WIDTH;
            int i3 = i2+1;
            *id++ = i0;
            *id++ = i2;
            *id++ = i1;
            *id++ = i1; 
            *id++ = i2; 
            *id++ = i3;
        }
    }
    
    // transfer
    for (glm::vec3& pos : verts)
        vertices.push_back(Vertex(pos, glm::vec3(0.0, 1.0, 0.0), glm::vec2(0.0)));
    
    for (GLuint& in : ind)
        indices.push_back(in);
    
    /*
    float startX = (size / 2) * -1;
    float endZ = (size / 2) * -1;
    
    float xIndex = 0;
    float zIndex = size;
    
    int count = 0;
    
    for (float x = startX; x < size; x += 1.0, xIndex++) {
        for (float z = size; z > endZ; z -= 1.0, zIndex--, count += 3) {
            // BROKEN
            vertices.push_back(Vertex(glm::vec3(x - 0.5, 0.0f, z + 0.5), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0))); // 0
            vertices.push_back(Vertex(glm::vec3(x - 0.5, 0.0f, z - 0.5), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0))); // 1
            vertices.push_back(Vertex(glm::vec3(x + 0.5, 0.0f, z + 0.5), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0))); // 2
            vertices.push_back(Vertex(glm::vec3(x + 0.5, 0.0f, z - 0.5), glm::vec3(0.0, 1.0, 0.0), glm::vec2(0))); // 3
            
            indices.push_back(count + 0);
            indices.push_back(count + 1);
            indices.push_back(count + 2);
            indices.push_back(count + 2);
            indices.push_back(count + 1);
            indices.push_back(count + 3);
        }
    }
    */
    wireframe = true;
    
    Geometry::setup();
}

PlaneGeometry::~PlaneGeometry() {}
