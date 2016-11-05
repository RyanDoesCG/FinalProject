/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  IndexedMeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef IndexedMeshComponent_hpp
#define IndexedMeshComponent_hpp

#include "ActorComponent.hpp"
#include "MeshComponent.hpp"
#include "../GLM/glm.hpp"
#include "../GLEW/GLEW.h"
#include "../GLFW/glfw3.h"
#include <vector>

class IndexedMeshComponent : public MeshComponent {
public:
     IndexedMeshComponent (std::vector<GLfloat>* v, std::vector<GLuint>* i);
    ~IndexedMeshComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
private:
    std::vector<GLuint>* indices;
    int totalIndices;
};

#endif /* IndexedMeshComponent_hpp */
