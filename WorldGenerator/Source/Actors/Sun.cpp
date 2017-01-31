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

Sun::Sun () : Model("sphere/sphere") {
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource", BASIC));
    Model::setScale(0.2);
    lightSource = this;
    setColour(vec3(1.0f, 1.0f, 1.0f));
}

Sun::~Sun () {
    
}

void Sun::draw(SceneCamera *camera) {
    Model::draw(camera);
}

void Sun::update(GameState state) {
    Model::update(state);
}
