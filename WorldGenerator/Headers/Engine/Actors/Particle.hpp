//
//  Particle.hpp
//  WorldGenerator
//
//  Created by user on 10/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

struct Particle {
    glm::vec3 col;
    glm::vec3 vel;
    glm::vec3 pos;
    glm::vec3 spawnSpan;
    int range;
    
    Particle(glm::vec3 p, glm::vec3 v, glm::vec3 s, int r) { pos = p; vel = v; spawnSpan = s; range = r; }
    
    void update (glm::vec3(emitter)) {
        pos += vel;
        if (vectorDistance(pos, emitter) > range)
            pos = glm::vec3(emitter.x + (rand() % (int)spawnSpan.x), emitter.y + (rand() % (int)spawnSpan.y), emitter.z + (rand() % (int)spawnSpan.z)); // causes all particles to reset at the same point :(
    }
};

#endif /* Particle_hpp */
