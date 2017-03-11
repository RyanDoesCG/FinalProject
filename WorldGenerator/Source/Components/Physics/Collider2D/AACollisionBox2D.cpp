//
//  AACollisionBox2D.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include <iostream>
#include "AACollisionBox2D.hpp"

AACollisionBox2D::AACollisionBox2D (glm::vec2 scale) {
    width  = scale.x;
    height = scale.y;
    
    position.x = 0 - (width * 0.5);
    position.y = 0 - (height * 0.5);
    
    colliding = false;
    type = 0;
}

AACollisionBox2D::~AACollisionBox2D () {
    
}

void AACollisionBox2D::simulate(double time) {
    colliding = false;
}

void AACollisionBox2D::scaleTo(glm::vec3 s) {
    this->width = s.x;
    this->height = s.y;
    
    position.x = 0 - (width * 0.5);
    position.y = 0 - (height * 0.5);
}

void AACollisionBox2D::moveTo(glm::vec3 p) {
    position.x = p.x - (width * 0.5);
    position.y = p.y - (height * 0.5);
    position.z = p.z;
}

glm::vec3 AACollisionBox2D::pos () {
    return glm::vec3(position.x + (width * 0.5), position.y + (height * 0.5), 0.0);
}

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

