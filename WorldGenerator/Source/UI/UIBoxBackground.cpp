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
    graphics->colour = glm::vec4(0.16, 0.16, 0.16, 0.5);
    graph->add(graphics);
}

UIBoxBackground::~UIBoxBackground () {
    
}

void UIBoxBackground::moveTo(glm::vec3 p) {
    graphics->position = p;
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


void UIBoxBackground::update () {

}
