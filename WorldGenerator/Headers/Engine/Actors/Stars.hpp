//
//  Stars.hpp
//  WorldGenerator
//
//  Created by user on 02/04/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Stars_hpp
#define Stars_hpp

#include "ParticleEmitter.hpp"
#include "ShaderCache.hpp"
#include "Random.hpp"
#include "CubeGeometry.hpp"

class Stars : public ParticleEmitter {
    public:
        Stars (GraphicsEngine* graph, PhysicsEngine* phys) : ParticleEmitter (graph, phys) {
            numParticles = 10000;
            for (int i = 0; i < numParticles; i++) {
                particles.push_back(Particle(
                    glm::vec3((180 * betterRand()), (180 * betterRand()), (180 * betterRand())),
                    glm::vec3(0, 0, 0),
                    glm::vec4(1),
                    glm::vec3(0),
                    glm::vec3(0.025),
                    position,
                    10000
                ));
            }
            
            sprite = new FlyweightGraphicsObject(
                new CubeGeometry(),
                new Material (ShaderCache::loadBasicShader("object"))
            );
            
            graph->add(sprite);
            
            for (Particle& p : particles) {
                sprite->instances.push_back(FlyweightInstance (p.position, glm::vec3(0.0), p.colour, p.scale));
            }
        }
    
       ~Stars () {
        
        }
};

#endif /* Stars_hpp */
