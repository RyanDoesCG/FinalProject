//
//  Particle.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include "glm.hpp"

using namespace glm;

struct Particle {
    Particle (vec3 p, vec3 v, vec4 c, vec3 d, vec3 s, vec3 origin, GLfloat ran):
        position   (p),
        velocity   (v),
        dampening  (d),
        colour     (c),
        scale      (s),
        spawnPoint (origin),
        range      (ran) {}
    
    void update () {
        position += velocity;
        if (length((spawnPoint - position)) > range)
            position = spawnPoint;
    }
    
    vec3 position;
    vec3 velocity;
    vec3 dampening;
    vec4 colour;
    vec3 scale;
    
    // control vars
    vec3 spawnPoint;
    GLfloat range;
};

#endif /* Particle_hpp */
