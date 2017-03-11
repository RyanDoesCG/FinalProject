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
    
    position      = glm::vec3(0.0f, 0.0f, 3.0f);   // in world space
    velocity      = glm::vec3(0.0, 0.0, 0.0);
    
    relativeFront = glm::normalize(glm::vec3(position - glm::vec3(0.0, 0.0, 0.0)));  // front from camera
    relativeRight = glm::vec3(1.0f, 0.0f, 0.0f);
    relativeUp    = glm::vec3(0.0f, 1.0f, 0.0f);   // up from camera
    worldUp       = glm::vec3(0.0f, 1.0f, 0.0f);
    
    aspectRatio = aspect;
    
    yaw = -90.0f;
    pitch = 0.0f;
    zoom = 45.0f;
    
    view = glm::lookAt(position, position + relativeFront, relativeUp);
    proj = glm::perspective(zoom, aspectRatio, 0.01f, 100.0f);
}

Camera::~Camera() {
    
}

glm::mat4 Camera::getProjectionMatrix () { return proj; }
glm::mat4 Camera::getViewMatrix       () { return view; }

void Camera::update () {
    position += velocity;
    
    relativeFront =  glm::normalize(glm::vec3(
        cos (glm::radians(yaw) * cos (glm::radians(pitch))),    // x
        sin (glm::radians(pitch)),                              // y
        sin (glm::radians(yaw) * cos (glm::radians(pitch)))     // z
    ));

    relativeRight = glm::normalize(glm::cross(relativeFront, worldUp));
    relativeUp    = glm::normalize(glm::cross(relativeRight, relativeFront));
    
    view = glm::lookAt(position, position + relativeFront, relativeUp);
    proj = glm::perspective(zoom, aspectRatio, 0.01f, 100.0f);
}
