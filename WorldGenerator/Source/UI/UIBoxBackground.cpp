//
//  UIBoxBackground.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "QuadGeometry.hpp"
#include "Material.hpp"
#include "UIBoxBackground.hpp"

UIBoxBackground::UIBoxBackground (GraphicsEngine* graph) {
    graphics = new GraphicsObject (
        new QuadGeometry(),
        new Material("object")
    );
    graphics->colour = glm::vec4(0.16, 0.16, 0.16, 0.65);
    graph->addToUI(graphics);
    
    setAlpha(0);
}

UIBoxBackground::~UIBoxBackground () {
    
}

void UIBoxBackground::moveTo(glm::vec3 p) {
    graphics->position = glm::vec3(p.x, p.y, -0.01);
}

void UIBoxBackground::scaleTo(glm::vec3 s) {
    graphics->scale = s;
}

void UIBoxBackground::setColour(glm::vec4 c) {
    graphics->colour = c;
}

void UIBoxBackground::setAlpha(GLfloat a) {
    graphics->colour.a = a;
}

void UIBoxBackground::update (State state) {
    // fading
    if (isHidden) fadeOut();
    if (!isHidden) fadeIn();
}

void UIBoxBackground::fadeIn () {
    if (graphics->colour.a < 0.5) {
        graphics->colour.a += 0.05;
    }
}

void UIBoxBackground::fadeOut () {
    if (graphics->colour.a > 0) {
        graphics->colour.a -= 0.05;
    }
}
