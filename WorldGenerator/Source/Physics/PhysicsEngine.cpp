/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsEngine.cpp
 *  Tribes
 *
 *  Created by user on 09/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Physics/PhysicsEngine.hpp"

PhysicsEngine::PhysicsEngine () {
    
}

PhysicsEngine::~PhysicsEngine () {
    
}

void PhysicsEngine::addToSimulation(Actor* actor) {
    scene.push_back(actor);
}

void PhysicsEngine::simulate(double time, GameState state) {
    
}
