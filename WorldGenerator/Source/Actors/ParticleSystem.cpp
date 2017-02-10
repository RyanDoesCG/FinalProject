//
//  ParticleSystem.cpp
//  WorldGenerator
//
//  Created by user on 03/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ParticleSystem.hpp"
#include "../../Headers/Engine/Utility/BetterRand.hpp"

ParticleSystem::ParticleSystem () {
    // graphics component
    sprite = Cube();
    sprite.setShader("unlitObject", BASIC);
    sprite.setColour(vec3(1.0f));
    sprite.setScale(0.05);
    
    // data model
    numParticles = 4000;
    particleRange = 100;
    xSpan = 100;
    ySpan = 100;
    zSpan = 100;
    
    for (int i = 0; i < numParticles; i++)
        particles.push_back(Particle(
            glm::vec3(this->getPosition().x + (rand() % xSpan), this->getPosition().y + (rand() % ySpan), this->getPosition().z + (rand() % zSpan)), // position
            glm::vec3(0.1, unsignedRand() * -1, 0),
            glm::vec3(xSpan, ySpan, zSpan),
            particleRange
        ));
}

ParticleSystem::~ParticleSystem () {
    
}

void ParticleSystem::draw (SceneCamera* camera) {
    for (int i = 0; i < numParticles; i++) {
        sprite.setPosition(particles.at(i).pos);
        sprite.update(RUNNING_FREEMODE);
        sprite.draw(camera);
    }
}

void ParticleSystem::update (GameState state) {
    for (int i = 0; i < numParticles; i++)
        particles.at(i).update(this->getPosition());
}
