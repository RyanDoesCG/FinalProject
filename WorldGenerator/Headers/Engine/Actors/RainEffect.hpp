//
//  RainEffect.hp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef RainEffect_hpp
#define RainEffect_hpp

#include "../Utility/Maths.hpp"
#include "../Utility/BetterRand.hpp"

#include "Actor.hpp"
#include "Actor.hpp"
#include "Cube.hpp"
#include <vector>

#include "Particle.hpp"

class RainEffect : public Actor {
public:
    RainEffect();
    ~RainEffect();
    
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

#endif /* RainEffect_hpp */
