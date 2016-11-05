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
     MeshComponent (std::vector<GLfloat>* v);
     MeshComponent ();
    ~MeshComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
protected:
    std::vector<GLfloat>* vertices;
    
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    
    int totalVertices;
};

#endif /* MeshComponent_hpp */
