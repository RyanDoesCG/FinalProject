//
//  Geometry.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef Geometry_hpp
#define Geometry_hpp

#include "Vertex.hpp"
#include "glew.h"
#include <vector>

class Geometry {
    public:
        Geometry ();
       ~Geometry ();
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        bool wireframe;
    
        virtual void render ();
    
    protected:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
    
        virtual void setup ();

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
};

#endif /* Geometry_hpp */
