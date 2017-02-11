//
//  RainEffect.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/RainEffect.hpp"

RainEffect::RainEffect () {
        // graphics component
    sprite = Cube();
    sprite.setShader("unlitObject", BASIC);
    sprite.setColour(vec3(0.8, 0.8, 0.9));
    sprite.setScale(glm::vec3(0.01, 0.2, 0.01));
    
        // data model
    numParticles = 4000;
    particleRange = 100;
    xSpan = 100;
    ySpan = 100;
    zSpan = 100;
    
    for (int i = 0; i < numParticles; i++)
        particles.push_back(Particle(
            glm::vec3(this->getPosition().x + (rand() % xSpan), this->getPosition().y + (rand() % ySpan), this->getPosition().z + (rand() % zSpan)), // position
            glm::vec3(0, unsignedRand() * -2, 0),
            glm::vec3(xSpan, ySpan, zSpan),
            particleRange
        ));
}

RainEffect::~RainEffect () {
    
}

void RainEffect::draw (SceneCamera* camera) {
    for (int i = 0; i < numParticles; i++) {
        sprite.setPosition(particles.at(i).pos);
        sprite.update(RUNNING_FREEMODE);
        sprite.draw(camera);
    }
}

void RainEffect::update (GameState state) {
    for (int i = 0; i < numParticles; i++)
        particles.at(i).update(this->getPosition());
}
