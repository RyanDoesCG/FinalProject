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
    
    flare1 = Quad();
    flare1.setScale(0.2);
    flare1.setPosition(glm::vec3(0.0, 0.0, 2.5));
    flare1.setShader("BasicBlack");
    
    flare2 = Quad();
    flare3 = Quad();
    flare4 = Quad();
}

Sun::~Sun () {
    
}

void Sun::draw(SceneCamera *camera) {
    Model::draw(camera);
   // flare1.draw(camera);
}

void Sun::update(GameState state) {
    Model::update(state);
    flare1.update(state);
}
