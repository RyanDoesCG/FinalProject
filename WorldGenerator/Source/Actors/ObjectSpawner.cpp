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

ObjectSpawner::ObjectSpawner (GraphicsEngine* graph, std::string pathToModel, glm::vec4 col, int num) {
    sprite = new FlyweightGraphicsObject (
        new ModelGeometry (pathToModel),
        new Material ("object")
    );
    
    numObjects = num;
    
    // Build Instances
    for (int i = 0; i < numObjects; i++) {
        glm::vec3 position = glm::vec3(betterRand() * 10, 0.5, betterRand() * 10);
        glm::vec3 rotation = glm::vec3(0);
        glm::vec4 colour   = col;
        glm::vec3 scale    = glm::vec3(0.25);
        
        sprite->instances.push_back(FlyweightInstance(position, rotation, colour, scale));
    }
    
    graph->add(sprite);
}

ObjectSpawner::~ObjectSpawner () {}

void ObjectSpawner::update(State state) {
    
}
