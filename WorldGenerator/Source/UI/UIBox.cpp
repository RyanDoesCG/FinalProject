//
//  UIBox.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "AACollisionBox2D.hpp"
#include "QuadGeometry.hpp"
#include "Material.hpp"
#include "UIBox.hpp"

UIBox::UIBox (GraphicsEngine* graph, PhysicsEngine* phys) {
    graphics = new GraphicsObject (
        QuadGeometry(),
        Material("object")
    );
    
    physics = new AACollisionBox2D(1, 1);
    
    graph->add(graphics);
    phys->addTo2D(physics);
}

UIBox::~UIBox () {

}

void UIBox::update () {
    physics->position = graphics->position = position;
    if (physics->colliding) graphics->colour = glm::vec4(0.41, 0.41, 0.41, 1.0);
    else                    graphics->colour = glm::vec4(0.21, 0.21, 0.21, 1.0);
}
