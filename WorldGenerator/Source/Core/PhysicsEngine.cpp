//
//  PhysicsEngine.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "PhysicsEngine.hpp"

PhysicsEngine::PhysicsEngine () {
    
}

PhysicsEngine::~PhysicsEngine () {
    
}

void PhysicsEngine::addTo2D(PhysicsObject2D *object) {
    world2D.push_back(object);
}

void PhysicsEngine::addTo3D(PhysicsObject3D *object) {
    world3D.push_back(object);
}

void PhysicsEngine::simulate(double time) {
    for (int i = 0; i < world2D.size(); i++) world2D.at(i)->simulate(time);
    for (int i = 0; i < world3D.size(); i++) world3D.at(i)->simulate(time);
}
