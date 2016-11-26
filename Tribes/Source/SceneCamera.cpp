/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SceneCamera.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 26/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/SceneCamera.hpp"

SceneCamera::SceneCamera (GLfloat width, GLfloat height) {
    movementSpeed = 0.15f;
    
    position      = vec3(0.0f, 0.0f, 3.0f);   // in world space
    relativeFront = vec3(0.0f, 0.0f, -1.0f);  // front from camera
    relativeUp    = vec3(0.0f, 1.0f, 0.0f);   // up from camera
    
    // Shader Transforms
    projection = glm::perspective (
        80.0f,
        width / height,
        0.01f,
        100.0f
    );
    
    /*
    view = lookAt (
        position,                  // position
        position + direction,      // target
        relativeUp                 // up
    );
    */
    
    view = glm::lookAt(position, target, relativeUp);
}

SceneCamera::~SceneCamera () {
    
}

mat4 SceneCamera::getProjectionTransform () {
    return projection;
}

mat4 SceneCamera::getViewTransform () {
    return view;
}

void SceneCamera::moveLeft() {
    position += normalize(cross(relativeFront, relativeUp)) * movementSpeed;
}

void SceneCamera::moveRight() {
    position -= normalize(cross(relativeFront, relativeUp)) * movementSpeed;
}

void SceneCamera::moveForward() {
    position += movementSpeed * relativeFront;

}

void SceneCamera::moveBackward() {
    position -= movementSpeed * relativeFront;
}

void SceneCamera::idle(double animationTimer) {
    GLfloat radius = 10.0f;
    position.x = sin(animationTimer) * radius;
    position.z = cos(animationTimer) * radius;
    
    view = glm::lookAt(position, relativeFront, relativeUp);
}

void SceneCamera::update () {
    view = glm::lookAt(position, position + relativeFront, relativeUp);
}
