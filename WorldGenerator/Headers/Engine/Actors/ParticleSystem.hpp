//
//  ParticleSystem.hpp
//  WorldGenerator
//
//  Created by user on 03/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include "Actor.hpp"
#include "Quad.hpp"
#include <vector>

class Particle {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec3 colour;
    float     ttl;
    Quad      sprite;
    
    Particle () :
        position(0.0f),
        velocity(1.0f),
        colour(0.12f),
        ttl(10.0f) {
        sprite.setShader("particle");
    }
    
    bool isAlive () {return ttl>0;}
    void draw (SceneCamera*camera) {
        sprite.setPosition(vec3(position.x, position.y, 0));
        sprite.setColour(colour);
        sprite.setScale(10);
        sprite.draw(camera);
    }
};

class ParticleSystem : public Actor {
    public:
        ParticleSystem();
       ~ParticleSystem();
    
        void draw (SceneCamera* camera) override;
        void update (GameState state) override;
    
    private:
        uint numberToProduce;   // total particles
        uint spawnRate;         // release per frame
        std::vector<Particle> particles;
};

#endif /* ParticleSystem_hpp */
