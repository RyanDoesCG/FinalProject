//
//  Camera.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera(GLfloat aspect) {
    movementSpeed = 0.004f;
    
    position      = glm::vec3(0.0f, 0.0f, -3.0f);   // in world space
    relativeFront = glm::normalize(glm::vec3(position - glm::vec3(0.0, 0.0, 0.0)));  // front from camera
    relativeRight = glm::vec3(1.0f, 0.0f, 0.0f);
    relativeUp    = glm::vec3(0.0f, 1.0f, 0.0f);   // up from camera
    worldUp       = glm::vec3(0.0f, 1.0f, 0.0f);

}

Camera::~Camera() {
    
}

glm::mat4 Camera::getProjectionMatrix () { return projection; }
glm::mat4 Camera::getViewMatrix       () { return view; }
