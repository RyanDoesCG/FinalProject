//
//  ParticleSystem.hpp
//  WorldGenerator
//
//  Created by user on 03/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include "../Utility/Maths.hpp"
#include "Actor.hpp"
#include "Cube.hpp"
#include <vector>

#include "Particle.hpp"

class ParticleSystem : public Actor {
    public:
        ParticleSystem();
       ~ParticleSystem();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void addLightSource (Actor* light) {
            sprite.setLightSource(light);
        }
    
    private:
        Cube sprite;
        uint numParticles;
        int particleRange;
        int xSpan;
        int ySpan;
        int zSpan;
    
        std::vector<Particle> particles;
    
        Actor* lightSource;
};

#endif /* ParticleSystem_hpp */
