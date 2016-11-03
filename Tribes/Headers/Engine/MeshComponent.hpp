/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MeshComponent_hpp
#define MeshComponent_hpp

#include "ActorComponent.hpp"
#include "../GLM/glm.hpp"
#include "../GLEW/GLEW.h"
#include "../GLFW/glfw3.h"
#include <vector>

class MeshComponent : public ActorComponent {
    public:
         MeshComponent (std::vector<GLfloat>* v, std::vector<GLuint>* i);
         MeshComponent (std::vector<GLfloat>* v);
        ~MeshComponent ();
    
        virtual void init() override;
        virtual void update() override;
    
    private:
        std::vector<GLfloat>* vertices;
        std::vector<GLuint>*  indices;
    
        GLuint VBO;
        GLuint VAO;
        GLuint EBO;
    
        enum MESH_TYPE {
            RAW_VERTICES,
            INDEXED
        };
    
        MESH_TYPE type;
    
        int totalVertices;
        int totalIndices;
};

#endif /* MeshComponent_hpp */
