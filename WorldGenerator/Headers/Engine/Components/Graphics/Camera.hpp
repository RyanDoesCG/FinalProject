//
//  Camera
//  WorldGenerator
//
//  Created by Ryan Needham on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include "matrix_transform.hpp"
#include "glew.h"
#include "glm.hpp"

class Camera {
    public:
        Camera(GLfloat aspect);
       ~Camera();
    
        glm::mat4 getProjectionMatrix ();
        glm::mat4 getViewMatrix       ();
    
        void moveTo (float x, float y, float z) { position = glm::vec3(x, y, z); }
    
    private:
        GLfloat movementSpeed;
        GLfloat sensitivity;
    
        GLfloat pitch;
        GLfloat roll;
        GLfloat yaw;
    
        glm::vec3 relativeFront; // Where we are looking
        glm::vec3 relativeRight; // right from the camera
        glm::vec3 relativeUp;    // up from the camrea
        glm::vec3 worldUp;       // up in world space
    
        glm::mat4 projection;
        glm::mat4 view;
    
        glm::vec3 position;
        glm::vec3 velocity;
};

#endif /* Camera_hpp */
