/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Planet_hpp
#define Planet_hpp

#include "Actor.hpp"
#include "../GLEW/glew.h"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"
#include "../GLM/glm.hpp"
#include <iostream>
#include <vector>

class Planet : public Actor {
public:
     Planet  ();
    ~Planet ();
    
    virtual void init() override;
    virtual void update() override;
    
private:
    void breakdownMesh ();  // morph octohedron into sphere
    void normaliseMesh ();  // generate terrain
    
    std::vector<GLfloat> vertices;
    
    // THESE SHOULD GO SOMEWHERE ELSE?!?!
    glm::mat4 modelMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};

#endif /* Planet_hpp */
