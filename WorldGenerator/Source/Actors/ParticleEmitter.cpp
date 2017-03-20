//
//  ParticleEmitter.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Random.hpp"
#include "ParticleEmitter.hpp"

ParticleEmitter::ParticleEmitter (GraphicsEngine* graph, PhysicsEngine* phys) {

}

ParticleEmitter::~ParticleEmitter () {

}

void ParticleEmitter::update (State state) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
        
        sprite->instances[i].position = particles[i].position;
        sprite->instances[i].rotation = glm::vec3(0, 0, 0);
        sprite->instances[i].colour   = particles[i].colour;
        sprite->instances[i].scale    = particles[i].scale;
    }
}
