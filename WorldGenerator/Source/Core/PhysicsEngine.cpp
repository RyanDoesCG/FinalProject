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

    // simulate movement
    for (PhysicsObject2D* o : world2D) o->simulate(time);
    for (PhysicsObject3D* o : world3D) o->simulate(time);
    
    // detect collisions (ORDER N^2, NOT GOOD)
    for (PhysicsObject2D* a : world2D) {
        for (PhysicsObject2D* b : world2D) {
            if (a != b) {
                if (a->isColliding(b)) {
                    a->colliding = true;
                    b->colliding = true;
                }
            }
        }
    }
    
    for (PhysicsObject3D* a : world3D) {
        for (PhysicsObject3D* b : world3D) {
            if (a != b) {
                if (a->isColliding(b)) {
                    a->colliding = true;
                    b->colliding = true;
                }
            }
        }
    }
    
    // resolve collisions
}
