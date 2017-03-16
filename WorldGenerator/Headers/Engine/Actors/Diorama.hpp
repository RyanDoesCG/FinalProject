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
#include "ObjectSpawner.hpp"
#include "HeightMap.hpp"

class Diorama: public GameObject {
    public:
        Diorama (GraphicsEngine* g, PhysicsEngine* p);
       ~Diorama ();
    
        virtual void update (State state) override;
    
    private:
        GraphicsObject* terrain;
        GraphicsObject* water;
    
        ObjectSpawner* trees;
        ObjectSpawner* rocks;
    
        ParticleEmitter* rain;
    
        HeightMap* heightmap;
    
        Mouse* mouse;
    
        glm::vec3 velocity;
    
        GLfloat amp;
};

#endif /* Diorama_hpp */
