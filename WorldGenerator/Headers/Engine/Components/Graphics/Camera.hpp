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
    
        void update ();
    
    private:
        glm::vec3 position;
        glm::vec3 velocity;
    
        glm::vec3 relativeFront;
        glm::vec3 relativeUp;
        glm::vec3 relativeRight;
        glm::vec3 worldUp;
    
        glm::mat4 view;
        glm::mat4 proj;
    
        GLfloat yaw;
        GLfloat pitch;
        GLfloat roll;
    
        GLfloat movementSpeed;
        GLfloat mouseSensitivity;
        GLfloat zoom;
    
        GLfloat aspectRatio;
    
};

#endif /* Camera_hpp */