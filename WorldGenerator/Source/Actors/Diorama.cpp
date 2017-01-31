/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Diorama.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 31/01/2017.
 *  Copyright © 2017 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Diorama.hpp"

Diorama::Diorama() : base("base/base") {

    // main terrain
    surface = GridPlane(40, 40);
    surface.setColour(glm::vec3(0.96f, 0.87f, 0.70f));
    
    
    // base
    base.setShader("litObject", BASIC);
    base.setColour(glm::vec3(0.62f, 0.32f, 0.17f));
    base.setScale(30);
    base.setPosition(glm::vec3(10.0, -30, 10.0));
}

Diorama::~Diorama () {
    
}

void Diorama::draw(SceneCamera *camera) {
    surface.draw(camera);
    base.draw(camera);
}

void Diorama::update(GameState state) {
    surface.update(state);
    base.update(state);
}
