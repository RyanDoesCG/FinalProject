/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Skybox.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Skybox.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"

Skybox::Skybox  (): Cube() {
    Cube::resize(100);
    Cube::colour = glm::vec3(1, 1, 1);
    Cube::shader = ShaderCache::loadShaderComponent("Skybox", BASIC);
    Cube::setPosition(glm::vec3(0.0, -1.0, 0.0));
    Cube::setColour(glm::vec3(0.15, 0.15, 0.15));
}

Skybox::~Skybox () {
    

}

void Skybox::draw(SceneCamera *camera) {
    Cube::draw(camera);
}

void Skybox::update(GameState state) {
    Cube::update(state);
}
