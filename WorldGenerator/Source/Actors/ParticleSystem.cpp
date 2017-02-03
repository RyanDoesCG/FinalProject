//
//  ParticleSystem.cpp
//  WorldGenerator
//
//  Created by user on 03/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem () {
    numberToProduce = 50;
    spawnRate = 2;
    
    for (int i = 0; i < numberToProduce; i++)
        particles.push_back(Particle());
}

ParticleSystem::~ParticleSystem () {
    
}

void ParticleSystem::draw (SceneCamera* camera) {
    // draw all particles
    for (int i = 0; i < numberToProduce; i++)
        if (particles.at(i).isAlive())
            particles.at(i).draw(camera);
}

void ParticleSystem::update (GameState state) {
    // spawn new particles
    for (int i = 0; i < spawnRate; i++) {
        
    }
    
    // update all particles
    for (int i = 0; i < numberToProduce; i++) {
        particles.at(i).ttl -= 0.1f;
        
        if (particles.at(i).isAlive()) {
            particles.at(i).position += particles.at(i).velocity;
        }
    }
}
