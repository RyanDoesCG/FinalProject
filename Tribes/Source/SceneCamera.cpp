/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SceneCamera.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 26/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/SceneCamera.hpp"
#include "../Headers/glfw/glfw3.h"

SceneCamera::SceneCamera (GLfloat width, GLfloat height) {
    movementSpeed = 0.05f;
    
    position      = vec3(0.0f, 0.0f, 3.0f);   // in world space
    relativeFront = vec3(0.0f, 0.0f, -1.0f);  // front from camera
    relativeRight = vec3(1.0f, 0.0f, 0.0f);
    relativeUp    = vec3(0.0f, 1.0f, 0.0f);   // up from camera
    worldUp       = vec3(0.0f, 1.0f, 0.0f);
    
    // Shader Transforms
    projection = glm::perspective (
        45.0f,
        width / height,
        0.1f,
        100.0f
    );
    
    view = glm::lookAt(position, position + relativeFront, relativeUp);
}

SceneCamera::~SceneCamera () {
    
}

mat4 SceneCamera::getProjectionTransform () { return projection; }
mat4 SceneCamera::getViewTransform       () { return view; }

void SceneCamera::moveLeft     () { position -= normalize(cross(relativeFront, relativeUp)) * movementSpeed; }
void SceneCamera::moveRight    () { position += normalize(cross(relativeFront, relativeUp)) * movementSpeed; }
void SceneCamera::moveForward  () { position += movementSpeed * relativeFront; }
void SceneCamera::moveBackward () { position -= movementSpeed * relativeFront; }

void SceneCamera::update (GameState state, SceneCamera* camera) {
    // USE DELTA TIMING TO SMOOTH MOVEMENT ACROSS CPUs
    
    if (!idling) {
        if (pitch > 90) { pitch = 90; }
        if (pitch < -90) { pitch = -90; }
        
        //relativeFront.x = cos(radians(pitch)) * cos(radians(yaw));
        //relativeFront.y = sin(radians(pitch));
        //relativeFront.z = cos(radians(pitch)) * sin(radians(yaw));

        relativeFront = normalize(relativeFront);
        relativeRight = normalize(cross(relativeFront, worldUp));
        relativeUp    = normalize(cross(relativeRight, relativeFront));
        view = glm::lookAt(position, position + relativeFront, relativeUp);
    }
    
    else {
        GLfloat radius = 5.0f;
        position.x = sin(glfwGetTime()/2) * radius;
        position.z = cos(glfwGetTime()/2) * radius;
        
        relativeFront   = normalize((position - vec3(0.0, 0.0, 0.0))); // always face origin
        relativeFront.x = relativeFront.x - (relativeFront.x * 2);
        relativeFront.y = relativeFront.y - (relativeFront.y * 2);
        relativeFront.z = relativeFront.z - (relativeFront.z * 2);
        view = glm::lookAt(position, position + relativeFront, relativeUp);
    }
}
