//
//  AACollisionBox2D.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include <iostream>
#include "AACollisionBox2D.hpp"

AACollisionBox2D::AACollisionBox2D (int w, int h) {
    width  = w;
    height = h;
    
    position.x = 0 - (width * 0.5);
    position.y = 0 - (height * 0.5);
    
    colliding = false;
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
        if (this->position.x < static_cast<AACollisionBox2D*>(other)->position.x + static_cast<AACollisionBox2D*>(other)->width &&
            this->position.x + this->width > static_cast<AACollisionBox2D*>(other)->position.x &&
            this->position.y < static_cast<AACollisionBox2D*>(other)->position.y + static_cast<AACollisionBox2D*>(other)->height &&
            this->height + this->position.y > static_cast<AACollisionBox2D*>(other)->position.y) {
            std::cout << std::endl;
            std::cout << "a: " << this->string() << std::endl;
            std::cout << "b: " << static_cast<AACollisionBox2D*>(other)->string() << std::endl;
            std::cout << std::endl;
            return true;
        }
    }
    return false;
}

std::string AACollisionBox2D::string () {
    return std::string("[")
        .append("(")
        .append(std::to_string(position.x))
        .append(", ")
        .append(std::to_string(position.y))
        .append(")")
        .append(" (")
        .append(std::to_string(width))
        .append(", ")
        .append(std::to_string(height))
        .append("]");
}

