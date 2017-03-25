//
//  ChunkCollider.cpp
//  WorldGenerator
//
//  Created by user on 21/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ChunkCollider.hpp"

ChunkCollider::ChunkCollider(glm::vec3 pos, glm::vec2 size) {
    
    position = pos;
    width = size.x;
    depth = size.y;
    colliding = false;
    type = 1;
    active = true;
    
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
            ChunkCollider* o = static_cast<ChunkCollider*>(other);
            
            contactLeft    = true; //testLeft    (o);
            contactRight   = testRight   (o);
            contactTop     = testTop     (o);
            contactBottom  = testBottom  (o);
            
            
            return (
                contactLeft  ||
                contactRight ||
                contactTop   ||
                contactBottom
            );
            
            /*
            if (this->position.x < o->position.x + o->depth &&
                this->position.x + this->width > o->position.x &&
                this->position.z < o->position.z + o->depth &&
                this->depth + this->position.z > o->position.z) {
                return true;
            }
            */
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

bool ChunkCollider::testLeft    (ChunkCollider* that) {
    return
        (pos().x - (width * 0.5)) > (that->pos().x + (that->width * 0.5)) &&   // x
        ((pos().z - (depth * 0.5)) < (that->pos().z + (that->depth * 0.5)) ||  // z ^
         (pos().z + (depth * 0.5)) < (that->pos().z - (that->depth * 0.5)));   // z v
}

bool ChunkCollider::testRight   (ChunkCollider* that) {
    return false;
}

bool ChunkCollider::testTop     (ChunkCollider* that) {
    return false;
}

bool ChunkCollider::testBottom  (ChunkCollider* that) {
    return false;
}
