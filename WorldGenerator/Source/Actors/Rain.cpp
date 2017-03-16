//
//  Rain.cpp
//  WorldGenerator
//
//  Created by user on 15/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Random.hpp"
#include "Rain.hpp"

Rain::Rain(GraphicsEngine* graph, PhysicsEngine* phys) : ParticleEmitter(graph, phys) {
    numParticles = 1000;
    for (int i = 0; i < numParticles; i++) {
        particles.push_back(Particle(
            glm::vec3(10 + (100 * betterRand()), position.y, 10 + (100 * betterRand())),
            glm::vec3(0, unsignedRand() * -1, 0),
            glm::vec4(1),
            glm::vec3(0),
            glm::vec3(0.25),
            position,
            100
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
}
