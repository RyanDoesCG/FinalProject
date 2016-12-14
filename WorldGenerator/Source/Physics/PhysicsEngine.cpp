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
    physicsWorld.push_back(actor);
}

void PhysicsEngine::simulate(double time, GameState state) {
    for (int i = 0; i < physicsWorld.size(); i++) {
        physicsWorld.at(i)->update(state);
    }
}
