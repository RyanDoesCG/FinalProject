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

UISlider::UISlider (GraphicsEngine* graph, PhysicsEngine* phys): marker(graph, phys), range (graph), counter(-2.7, -2.095, -1.49) {
    litColour = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);
    
    marker.scaleTo (glm::vec3(0.1, 0.2, 1));
    range.scaleTo  (glm::vec3(1.25, 0.05, 1));
    
    marker.physics->position.x = 2.095;
    
    mouse = InputManager::getMouseHandle();
}

UISlider::~UISlider () {
    
}

void UISlider::moveTo(glm::vec3 p) {
    marker.moveTo(p);
    range.moveTo(p);
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

void UISlider::update (State state) {
    if (mouse->leftButtonDown() && marker.isSelected() && mouse->getXoffset() != lastMouseX) {
        if (mouse->getXoffset() > 0) counter.incrementBy(mouse->getXoffset());
        if (mouse->getXoffset() < 0) counter.decrementBy(mouse->getXoffset());

        marker.physics->position.x = counter.getValue();
        lastMouseX = mouse->getXoffset();
    }
    std::cout << " x: " << marker.graphics->position.x << std::endl;
    
    // fading
    if (isHidden) fadeOut();
    if (!isHidden) fadeIn();
    
    marker.update(state);
    range.update(state);
    
   // moveTo(glm::vec3(counter.getValue(), marker.position.y, marker.position.z));
}

void UISlider::fadeIn() {
    marker.fadeIn();
    range.fadeIn();
}

void UISlider::fadeOut() {
    marker.fadeOut();
    range.fadeOut();
}
