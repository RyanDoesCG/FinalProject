//
//  ParticleEmitter.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ParticleEmitter_hpp
#define ParticleEmitter_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"

#include "FlyweightGraphicsObject.hpp"

#include "Particle.hpp"

#include <vector>

class ParticleEmitter: public GameObject {
    public:
        ParticleEmitter (GraphicsEngine* graph, PhysicsEngine* phys);
       ~ParticleEmitter ();
    
        virtual void update (State state) override;
    
    protected:
        std::vector<Particle> particles;
        GLfloat numParticles;
    
        FlyweightGraphicsObject* sprite;
};

#endif /* ParticleEmitter_hpp */
