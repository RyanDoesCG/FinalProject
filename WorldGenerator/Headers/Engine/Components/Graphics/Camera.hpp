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
#include "InputManager.hpp"
#include "State.hpp"

class Camera {
    public:
        Camera(GLfloat aspect);
       ~Camera();
    
        glm::mat4 getProjectionMatrix ();
        glm::mat4 getViewMatrix       ();
    
        glm::mat4 getDefaultProjectionMatrix (); // for renderer
        glm::mat4 getDefaultViewMatrix       (); // for renderer
    
        //void teleportTo (float x, float y, float z) { position = glm::vec3(x, y, z); }
        //void moveTo     (float x, float y, float z) {  }
    
        void update (State state);
    
        glm::vec3 position;
        glm::vec3 velocity;
    
    private:
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
    
        Keyboard* keys;
        Mouse* mouse;
    
        GLfloat aspectRatio;
    
        struct MovementTarget {
            MovementTarget (glm::vec3 pos, glm::vec3 rot):
                position(pos),
                rotation(rot) {}
            
            MovementTarget ():
                position(0),
                rotation(0) {}
            
            glm::vec3 position;
            glm::vec3 rotation;
        };
    
        MovementTarget movement;
    
};

#endif /* Camera_hpp */
