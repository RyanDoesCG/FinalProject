//
//  Diorama.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Diorama_hpp
#define Diorama_hpp

#include "ParticleEmitter.hpp"
#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "TreeSpawner.hpp"
#include "RockSpawner.hpp"
#include "HeightMap.hpp"
#include "Biome.hpp"

class Diorama: public GameObject {
    public:
        Diorama (GraphicsEngine* g, PhysicsEngine* p);
       ~Diorama ();
    
        virtual void update (State state) override;
    
        void removeFromWorld ();
        void addToWorld ();
    
        void setRenderDistance (GLfloat val);
        void setAmplitude      (GLfloat val);
        void setSeaLevel       (GLfloat val);
        void changeHeightMap   ();
    
    private:
        void updateUniforms ();
        void pickBiome ();
    
        Biome* biome;
    
        GraphicsEngine* graphEng;
    
        GraphicsObject* terrain;
        GraphicsObject* water;
        GraphicsObject* base;
    
        ParticleEmitter* stars;
    
        TreeSpawner* trees;
        RockSpawner* rocks;
    
        ParticleEmitter* rain;
    
        HeightMap* heightmap;
    
        Mouse* mouse;
        Keyboard* keys;
    
        glm::vec3 velocity;
    
        GLfloat renderDistance;
        GLfloat seaLevel;
        GLfloat amp;
};

#endif /* Diorama_hpp */
