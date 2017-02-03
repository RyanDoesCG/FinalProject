/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Sun.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 14/12/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Sun.hpp"
#include "../../Headers/Engine/Utility/TextureCache.hpp"
#include "../../Headers/GLFW/glfw3.h"

Sun::Sun () : Model("sphere/sphere") {
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource", BASIC));
    Model::setScale(0.01);
    lightSource = this;
    setColour(vec3(1.0f, 1.0f, 1.0f));
}

Sun::~Sun () {
    
}

void Sun::draw(SceneCamera *camera) {
    Model::draw(camera);
}

void Sun::update(GameState state) {
    
    float radius = 80;
    float speed = 12;
    
    setPosition(glm::vec3(0, sin(glfwGetTime()/speed) * radius, cos(glfwGetTime()/speed) * radius));
    
    if (position.y > 0) {
        glClearColor (
            (0.81f * (position.y/100)) + 0.12,
            (0.78f * (position.y/100)) + 0.12,
            (0.71f * (position.y/100)) + 0.12,
            1.0f
        );
    } else {
        glClearColor(0.12, 0.12, 0.12, 1.0f);
    }
    
    Model::update(state);
}
