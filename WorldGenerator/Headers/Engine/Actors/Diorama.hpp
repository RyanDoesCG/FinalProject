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

class Diorama: public GameObject {
    public:
        Diorama (GraphicsEngine* g, PhysicsEngine* p);
       ~Diorama ();
    
        virtual void update (State state) override;
    
        void setRenderDistance (GLfloat val);
        void setAmplitude      (GLfloat val);
        void setSeaLevel       (GLfloat val);
    
    private:
        void updateUniforms ();
    
        GraphicsObject* terrain;
        GraphicsObject* water;
    
        TreeSpawner* trees;
        RockSpawner* rocks;
    
        ParticleEmitter* rain;
    
        HeightMap* heightmap;
    
        Mouse* mouse;
    
        glm::vec3 velocity;
    
        GLfloat renderDistance;
        GLfloat seaLevel;
        GLfloat amp;
};

#endif /* Diorama_hpp */
