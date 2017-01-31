/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SceneCamera.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 26/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/SceneCamera.hpp"
#include "../../Headers/glfw/glfw3.h"

SceneCamera::SceneCamera (GLfloat width, GLfloat height) {
    movementSpeed = 0.4f;
    
    position      = vec3(0.0f, 0.0f, 3.0f);   // in world space
    relativeFront = normalize(vec3(position - vec3(0.0, 0.0, 0.0)));  // front from camera
    relativeRight = vec3(1.0f, 0.0f, 0.0f);
    relativeUp    = vec3(0.0f, 1.0f, 0.0f);   // up from camera
    worldUp       = vec3(0.0f, 1.0f, 0.0f);
    
    // Shader Transforms
    projection = glm::perspective (
        45.0f,
        width / height,
        0.001f,
        1000.0f
    );
    
    view = glm::lookAt(position, position + relativeFront, relativeUp);
    
    reset();
}

SceneCamera::~SceneCamera () {
    
}

mat4 SceneCamera::getProjectionTransform () { return projection; }
mat4 SceneCamera::getViewTransform       () { return view; }

void SceneCamera::moveLeft     () { position -= normalize(cross(relativeFront, relativeUp)) * movementSpeed; }
void SceneCamera::moveRight    () { position += normalize(cross(relativeFront, relativeUp)) * movementSpeed; }

void SceneCamera::moveForward   () { position += movementSpeed * relativeFront; }
void SceneCamera::moveForwardAt (float speed) { position += speed * movementSpeed * relativeFront; }

void SceneCamera::moveBackward () { position -= movementSpeed * relativeFront; }
void SceneCamera::moveBackwardAt (float speed) { position -= speed * movementSpeed * relativeFront; }

void SceneCamera::reset () {
    position = vec3(71.0869, 15.5143, 29.0421);
    pitch = -20.65;
    roll = 0;
    yaw = -159;
}

void SceneCamera::draw (SceneCamera* camera) {
    

}

void SceneCamera::update (GameState state) {
    switch (state) {
        case MAIN_MENU: {
            // lock position
            position = vec3(-1.48968, 25.1779, 38.4063);
            
            relativeFront.x = 0.2 * (cos(radians(yaw)) * cos(radians(pitch)));
            relativeFront.y = 0.2 * (sin(radians(pitch)));
            relativeFront.z = 0.2 * (sin(radians(yaw)) * cos(radians(pitch)));
            
            // limit movement
            // TO DO
            
            relativeFront = normalize(relativeFront);
            relativeRight = normalize(cross(relativeFront, worldUp));
            relativeUp    = normalize(cross(relativeRight, relativeFront));
            view = glm::lookAt(position, position + relativeFront, relativeUp);
            break;
        }
        case RUNNING_FREEMODE: {
            
            // 0 radians causes flip
            relativeFront.x = cos(radians(yaw)) * cos(radians(pitch));
            relativeFront.y = sin(radians(pitch));
            relativeFront.z = sin(radians(yaw)) * cos(radians(pitch));
            
            relativeFront = normalize(relativeFront);
            relativeRight = normalize(cross(relativeFront, worldUp));
            relativeUp    = normalize(cross(relativeRight, relativeFront));
            view = glm::lookAt(position, position + relativeFront, relativeUp);
            break;
        }
            
        case RUNNING_EDITMODE: {
            
            relativeFront = normalize(relativeFront);
            relativeRight = normalize(cross(relativeFront, worldUp));
            relativeUp    = normalize(cross(relativeRight, relativeFront));
            view = glm::lookAt(position, position + relativeFront, relativeUp);
            break;
        }
    }
    
    std::cout << std::endl;
    std::cout << position.x << ", " << position.y << ", " << position.z << std::endl;
    std::cout << pitch << ", " << yaw << ", " << roll << std::endl;
    std::cout << std::endl;
}
