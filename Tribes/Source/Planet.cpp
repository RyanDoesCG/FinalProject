//
//  Planet.cpp
//  Tribes
//
//  Created by user on 30/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/ShaderCache.hpp"

Planet::Planet (): Model("sphere/sphere") {

    setColour(glm::vec3(0.5, 0.5, 0.5));
    setShader("Planet");
    
    PerlinNoiseMachine::distortMe(&(meshes.back().vertices));
}

Planet::~Planet () {
    
}

void Planet::update(GameState state, SceneCamera *camera) {
    
    switch (state) {
        case MAIN_MENU:
            setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            setPosition(glm::vec3(1.0, 0.0, 0.0));
            break;
        case RUNNING_FREEMODE:
            setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            setPosition(glm::vec3(0.0, 0.0, 0.0));
            break;
    }
    
    shader->update();

    Model::update(state, camera);
}
