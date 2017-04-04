//
//  Planet.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Planet_hpp
#define Planet_hpp

#include "PhysicsEngine.hpp"
#include "PhysicsObject2D.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "HeightMap.hpp"
#include "Stars.hpp"
#include "Biome.hpp"

class Planet: public GameObject {
    public:
        Planet (GraphicsEngine* g, PhysicsEngine* p);
       ~Planet ();
    
        virtual void update (State state) override;
    
        void removeFromWorld ();
        void addToWorld ();
    
        void setAmplitude (float v) {amp = v;}
        void changeHeightMap ();
    
        void updateUniforms ();
    
    private:
        GraphicsEngine* graphEng;
        GraphicsObject* terrain;
        GraphicsObject* water;
    
        ParticleEmitter* stars;
    
        void pickBiome();
        Biome* biome;
    
        Mouse* mouse;
        Keyboard* keys;
    
        glm::vec3 velocity;
    
        GLfloat resty;
        GLfloat restx;
    
        HeightMap* heightmap;
    
        GLfloat maxScale = 10;
        GLfloat minScale = 4.5;
    
        GLfloat amp;
        GLfloat mode;
};

#endif /* Planet_hpp */
