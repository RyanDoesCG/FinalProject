//
//  AACollisionBox2D.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "AACollisionBox2D.hpp"

AACollisionBox2D::AACollisionBox2D (int w, int h) {
    width  = w;
    height = h;
    
    type = 0;
}

AACollisionBox2D::~AACollisionBox2D () {
    
}

void AACollisionBox2D::simulate(double time) {
    
}

/*
bool AACollisionBox2D::isColliding(AACollisionBox2D *other) {

}
*/

bool AACollisionBox2D::isColliding(PhysicsObject2D* other) {
    if (other->type == 0) {
        if (this->position.x < other->position.x + static_cast<AACollisionBox2D*>(other)->width &&
            this->position.x + this->width > other->position.x &&
            this->position.y < other->position.y + static_cast<AACollisionBox2D*>(other)->height &&
            this->height + this->position.y > other->position.y) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

