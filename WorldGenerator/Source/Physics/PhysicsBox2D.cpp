//
//  PhysicsBox2D.cpp
//  Tribes
//
//  Created by Ryan Needham on 04/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Physics/PhysicsBox2D.hpp"

PhysicsBox2D::PhysicsBox2D (glm::vec3 minExtents, glm::vec3 maxExtents) {
    minimumExtents = minExtents;
    maximumExtents = maxExtents;
}

PhysicsBox2D::~PhysicsBox2D () {
    
}

void PhysicsBox2D::init () {
    
}

void PhysicsBox2D::update () {
    
}

Intersection PhysicsBox2D::detectIntersection (PhysicsBox2D* other) {
    
    // calculate distances from other on each side
    glm::vec3 distanceOne = other->getMinimumExtents() - this->getMaximumExtents();
    glm::vec3 distanceTwo = other->getMaximumExtents() - this->getMinimumExtents();
    
    // find the largest of the two
    glm::vec3 distance = glm::max(distanceOne, distanceTwo);
    
    // doesnt work... yet...
    float maxValue = 0.0f;
    
    for (unsigned int i = 0; i < distance.length(); i++)
        if (maxValue < distance[i]) maxValue = distance[i];
    
    Intersection intersect(maxValue < 0, maxValue);
    return intersect;
}
