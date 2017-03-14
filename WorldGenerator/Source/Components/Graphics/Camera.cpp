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
    
    movement = MovementTarget(position, glm::vec3(-90, 0.0, 45));
    
    yaw = movement.rotation.x;
    pitch = movement.rotation.y;
    zoom = movement.rotation.z;
    
    view = glm::lookAt(position, position + relativeFront, relativeUp);
    proj = glm::perspective(zoom, aspectRatio, 0.01f, 1000.0f);
    
    mouse = InputManager::getMouseHandle();
}

Camera::~Camera() {
    
}

glm::mat4 Camera::getProjectionMatrix () { return proj; }
glm::mat4 Camera::getViewMatrix       () { return view; }

glm::mat4 Camera::getDefaultProjectionMatrix () { return proj; }
glm::mat4 Camera::getDefaultViewMatrix       () { return glm::lookAt(position, position + glm::normalize(glm::vec3(position - glm::vec3(0.0, 0.0, 0.0))), glm::vec3(0.0, 1.0, 0.0)); }

void Camera::update (State s) {
    switch (s) {
        case MENU: {
            GLfloat radius = 2;
            position.x = (sin(glfwGetTime()*0.08) * radius);
            position.z = (cos(glfwGetTime()*0.08) * radius);
            relativeFront =  glm::normalize(glm::vec3(position - glm::vec3(0.0, 0.0, 0.0)));
            break;
        }
        
        case VIEW: {
            break;
        }
        
        default: break;
    }

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
