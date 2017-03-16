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
/*
    numParticles = 1000;
    for (int i = 0; i < numParticles; i++) {
        particles.push_back(Particle(
            glm::vec3(10 + (100 * betterRand()), 10 + (100 * betterRand()), 10 + (100 * betterRand())),
            glm::vec3(0, 0, 0),
            glm::vec4(1),
            glm::vec3(0),
            glm::vec3(0.25),
            position,
            10000
        ));
    }
    
    sprite = new FlyweightGraphicsObject(
        new QuadGeometry(),
        new Material ("object")
    );
    
    graph->add(sprite);
    
    for (Particle& p : particles) {
        sprite->instances.push_back(FlyweightInstance (p.position, glm::vec3(0.0), p.colour, p.scale));
    }
*/
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
