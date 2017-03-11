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
    
    physics = new AACollisionBox2D(glm::vec2(1, 0.5));
    
    graph->add(graphics);
    phys->addTo2D(physics);
}

UIBox::~UIBox () {

}

void UIBox::moveTo(glm::vec3 p) {
    graphics->position = p;
    physics->moveTo(p);
}

void UIBox::scaleTo(glm::vec3 s) {
    graphics->scale = s;
    physics->scaleTo(s);
}

void UIBox::setColour(glm::vec4 c) {
    graphics->colour = c;
}

void UIBox::setAlpha(GLfloat a) {
    graphics->colour.a = a;
}

bool UIBox::isColliding() {
    return physics->colliding;
}

void UIBox::update () {
    graphics->position = physics->pos ();
    
    if (physics->colliding) graphics->colour = glm::vec4(0.41, 0.41, 0.41, 1.0);
    else                    graphics->colour = glm::vec4(0.21, 0.21, 0.21, 1.0);
}
