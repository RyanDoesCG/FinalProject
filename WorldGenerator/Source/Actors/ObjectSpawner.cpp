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

ObjectSpawner::ObjectSpawner (GraphicsEngine* graph, std::string pathToModel, HeightMap* map, glm::vec4 col, glm::vec3 scl, int num) {
    sprite = new FlyweightGraphicsObject (
        new ModelGeometry (pathToModel),
        new Material ("object_spawned", map->getID())
    );
    
    numObjects = num;
    
    // Build Instances
    for (int i = 0; i < numObjects; i++) {
        glm::vec3 position = glm::vec3(unsignedRand() * 20, 0, unsignedRand() * 20);
        glm::vec3 rotation = glm::vec3(0);
        glm::vec4 colour   = col;
        glm::vec3 scale    = scl;
        
        //position.y += map->getHeightAt((position.x) * 0.1, (1 + position.z) * 0.1) * 10;
        
        std::cout << "  x : " << position.x << "(" << position.x / 20 << ")\t" << "z : " << position.z << std::endl;
        sprite->instances.push_back(FlyweightInstance(position, rotation, colour, scale));
    }
    
    graph->add(sprite);
}

ObjectSpawner::~ObjectSpawner () {}

void ObjectSpawner::update(State state) {
    
}
