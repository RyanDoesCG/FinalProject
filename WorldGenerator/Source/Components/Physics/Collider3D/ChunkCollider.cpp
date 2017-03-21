//
//  ChunkCollider.cpp
//  WorldGenerator
//
//  Created by user on 21/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ChunkCollider.hpp"

ChunkCollider::ChunkCollider(glm::vec3 pos) {
    
    position = pos;
    colliding = false;
    type = 1;
    
    contactLeft   = false;
    contactRight  = false;
    contactTop    = false;
    contactBottom = false;
}

ChunkCollider::~ChunkCollider () {
    
}

void ChunkCollider::simulate(double time) {
    colliding     = false;
    contactLeft   = false;
    contactRight  = false;
    contactTop    = false;
    contactBottom = false;
}

bool ChunkCollider::isColliding(PhysicsObject3D *other) {
    if (active && other->active) {
        if (other->type == 1) {
            // TO - DO: 2D collision on x, z, recording side
            if (this->position.x < static_cast<ChunkCollider*>(other)->position.x + static_cast<ChunkCollider*>(other)->depth &&
                this->position.x + this->width > static_cast<ChunkCollider*>(other)->position.x &&
                this->position.z < static_cast<ChunkCollider*>(other)->position.z + static_cast<ChunkCollider*>(other)->depth &&
                this->depth + this->position.z > static_cast<ChunkCollider*>(other)->position.z) {
                return true;
            }
        }
    }
    return false;
}

void ChunkCollider::scaleTo (glm::vec3 s) {}
void ChunkCollider::moveTo  (glm::vec3 p) {}

glm::vec3 ChunkCollider::pos () {
    return position;
}

bool ChunkCollider::touchingLeft   () { return contactLeft; }
bool ChunkCollider::touchingRight  () { return contactRight; }
bool ChunkCollider::touchingTop    () { return contactTop; }
bool ChunkCollider::touchingBottom () { return contactBottom; }
