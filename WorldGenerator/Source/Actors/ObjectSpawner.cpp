//
//  ObjectSpawner.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "ModelGeometry.hpp"
#include "ObjectSpawner.hpp"
#include "Random.hpp"
#include "BasicShader.hpp"

ObjectSpawner::ObjectSpawner (GraphicsEngine* graph, std::string pathToModel, HeightMap* map, glm::vec4 col, glm::vec3 scl, int num) {
    sprite = new FlyweightGraphicsObject (
        new ModelGeometry (pathToModel),
        new Material (new BasicShader("object_spawned"), map->getID())
    );
    
    numObjects = num;
    
    // Pick Concentration Points
    for (int i = 0; i < numObjects; i++)
        concentrationPoints.push_back(glm::vec3(unsignedRand() * 20, 0, unsignedRand() * 20));
    
    
    // Scatter Objects around these points
    for (glm::vec3& point: concentrationPoints) {
        for (int i = 0; i < (int)(unsignedRand() * 10); i++) {
            glm::vec3 position = glm::vec3(point.x + betterRand(), 0, point.z + betterRand());
            glm::vec3 rotation = glm::vec3(0);
            glm::vec4 colour   = col;
            glm::vec3 scale    = scl;
            
            sprite->instances.push_back(FlyweightInstance(position, rotation, colour, scale));
        }
    }
    
    graph->add(sprite);
}

ObjectSpawner::~ObjectSpawner () {}

void ObjectSpawner::update(State state) {
    
}
