/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Camera.hpp
 *  ShaderToy
 *
 *  Created by ryan needham on 17/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Camera_hpp
#define Camera_hpp

#include "../GLM/glm.hpp"

#include <iostream>

class Camera {
    public:
        Camera (const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
//            perspectiveMatrix = glm::perspective(fov, aspect, zNear, zFar);
            cameraPosition    = pos;
            forward           = glm::vec3(0, 0, 1); // z axis
            upward            = glm::vec3(0, 1, 0); // y axis
        }

        ~Camera () {
        
        }
    
        inline glm::mat4 getViewProjection () const {
//            return perspectiveMatrix * glm::lookAt(cameraPosition, cameraPosition + forward, upward);
              return *new glm::mat4();// PLACEHOLDER
        }
    
        inline glm::vec3& getForward () { return forward; }
        inline glm::vec3& getUpward  () { return upward;  }
    
        void moveUp      () {cameraPosition.y += 0.1f;}
        void moveDown    () {cameraPosition.y -= 0.1f;}
        void moveLeft    () {cameraPosition.x -= 0.1f;}
        void moveRight   () {cameraPosition.x += 0.1f;}
        void moveBack    () {cameraPosition.z -= 0.1f;}
        void moveForward () {cameraPosition.z += 0.1f;}

    private:
        glm::mat4 perspectiveMatrix;
        glm::vec3 cameraPosition;
        glm::vec3 forward;
        glm::vec3 upward;

};

#endif /* Camera_hpp */
