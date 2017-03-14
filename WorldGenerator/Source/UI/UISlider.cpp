//
//  UISlider.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "AACollisionBox2D.hpp"
#include "QuadGeometry.hpp"
#include "Material.hpp"
#include "UISlider.hpp"

UISlider::UISlider (GraphicsEngine* graph, PhysicsEngine* phys): marker(graph, phys) {
    litColour = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);
}

UISlider::~UISlider () {
    
}

void UISlider::moveTo(glm::vec3 p) {
    marker.moveTo(p);
}

void UISlider::scaleTo(glm::vec3 s) {
    marker.scaleTo(s);
}

void UISlider::setColour(glm::vec4 c) {
    marker.setColour(c);
}

void UISlider::setAlpha(GLfloat a) {
    marker.setAlpha(a);
}

void UISlider::activatePhysics   () { marker.activatePhysics(); }
void UISlider::deactivatePhysics () { marker.deactivatePhysics(); }

bool UISlider::isSelected() {
    return marker.isSelected();
}

void UISlider::update () {
    marker.update();
}

void UISlider::fadeIn() {
    marker.fadeIn();
}

void UISlider::fadeOut() {
    marker.fadeOut();
}
