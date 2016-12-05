/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Skybox.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Skybox.hpp"
#include "../Headers/Engine/ShaderCache.hpp"

Skybox::Skybox  () {
    Cube::resize(100);
    Cube::colour = glm::vec3(1, 1, 1);
    Cube::shader = ShaderCache::loadShaderComponent("BasicBlack");
    Cube::setPosition(glm::vec3(0.0, -1.0, 0.0));
}

Skybox::~Skybox () {

}
