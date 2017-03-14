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
        new QuadGeometry(),
        new Material("object")
    );
    
    physics = new AACollisionBox2D(glm::vec2(1, 0.5));
    
    graph->addToUI (graphics);
    phys->addTo2D  (physics);
    
    litColour   = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);
    
    graphics->colour = glm::vec4(0.51, 0.51, 0.51, 1.0);
    
    setAlpha(0);
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

void UIBox::activatePhysics   () { physics->active = true; }
void UIBox::deactivatePhysics () { physics->active = false; }

bool UIBox::isSelected() {
    return physics->colliding;
}

void UIBox::update (State state) {
    graphics->position = physics->pos ();
    
    // visual feedback
    if (physics->colliding)  { light   ();  }
    if (!physics->colliding) { unlight (); }
    
    // fading
    if (isHidden) fadeOut();
    if (!isHidden) fadeIn();
}

void UIBox::light () {
    if (graphics->colour.r < litColour.r) {
        graphics->colour.r += 0.01;
        graphics->colour.g += 0.01;
        graphics->colour.b += 0.01;
    }
}

void UIBox::unlight () {
    if (graphics->colour.r > unlitColour.r) {
        graphics->colour.r -= 0.01;
        graphics->colour.g -= 0.01;
        graphics->colour.b -= 0.01;
    }
}

void UIBox::fadeIn () {
    if (graphics->colour.a < 1) {
        graphics->colour.a += 0.05;
    }
}

void UIBox::fadeOut () {
    if (graphics->colour.a > 0) {
        graphics->colour.a -= 0.05;
    }
}
