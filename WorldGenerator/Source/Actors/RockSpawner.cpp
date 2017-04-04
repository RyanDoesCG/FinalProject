//
//  RockSpawner.cpp
//  WorldGenerator
//
//  Created by user on 18/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "RockSpawner.hpp"
#include "ModelGeometry.hpp"
#include "ShaderCache.hpp"

#include "Random.hpp"

RockSpawner::RockSpawner ( GraphicsEngine* graph, std::string path, HeightMap* map, glm::vec4 col, glm::vec3 scl, int count ) {
    sprite = new FlyweightGraphicsObject (
        new ModelGeometry (path),
        new Material (ShaderCache::loadBasicShader("object_spawned"), map->getID())
    );
    
    numObjects = count;
    
    // Pick Concentration Points
    for (int i = 0; i < numObjects; i++)
        concentrationPoints.push_back(glm::vec3(unsignedRand() * 20, 0, unsignedRand() * 20));
    
    
    // Scatter Objects around these points
    for (glm::vec3& point: concentrationPoints) {
        glm::vec3 position = glm::vec3(point.x + betterRand() * 0.2, 0, point.z + betterRand() * 0.2);
        glm::vec3 rotation = glm::vec3(0);
        glm::vec4 colour   = col * glm::vec4(0.75 + (fmod(unsignedRand(), 0.5)));
        glm::vec3 scale    = scl * glm::vec3(2);
        
        colour.a = 1.0;
        
        sprite->instances.push_back(FlyweightInstance(position, rotation, colour, scale));
    
        for (int i = 0; i < 50; i++) {
            glm::vec3 position = glm::vec3(point.x + betterRand() * 0.2, 0, point.z + betterRand() * 0.2);
            glm::vec3 rotation = glm::vec3(0); //(betterRand(), betterRand(), betterRand());
            glm::vec4 colour   = col * glm::vec4(0.75 + (fmod(unsignedRand(), 0.5)));
            glm::vec3 scale    = scl;
            
            colour.a = 1.0;
            
            sprite->instances.push_back(FlyweightInstance(position, rotation, colour, scale));
        }
    }
    
    graph->add(sprite);
}

RockSpawner::~RockSpawner () {
    sprite->shouldDraw(false);
}
