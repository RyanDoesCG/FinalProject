//
//  UIPlusMinus.cpp
//  WorldGenerator
//
//  Created by user on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIPlusMinus.hpp"

UIPlusMinus::UIPlusMinus (GraphicsEngine* graph, PhysicsEngine* phys):
    UIBox       (graph, phys),
    plusButton  (graph, phys),
    minusButton (graph, phys) {

    scaleTo(glm::vec3(2, 1, 1));
}

UIPlusMinus::~UIPlusMinus () {
    
}

void UIPlusMinus::update() {
    UIBox::update();
}
