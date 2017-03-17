//
//  UIPlusMinus.cpp
//  WorldGenerator
//
//  Created by user on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UIPlusMinus.hpp"

UIPlusMinus::UIPlusMinus (GraphicsEngine* graph, PhysicsEngine* phys): plus (graph, phys), minus (graph, phys), frame (graph), counter(-2.7, -2.095, -1.49) {
    litColour   = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);
    
    plus.scaleTo (glm::vec3(0.2, 0.2, 1));
    minus.scaleTo(glm::vec3(0.2, 0.2, 1));
    
    frame.scaleTo  (glm::vec3(1.2, 0.275, 1));
    
    plus.physics->position.x = 2.095;
    minus.physics->position.x = 2.095;
    
    plus.setColour(glm::vec4(0.9, 0.9, 0.9, 1.0));
    minus.setColour(glm::vec4(0.1, 0.1, 0.1, 1.0));
    
    mouse = InputManager::getMouseHandle();
}

UIPlusMinus::~UIPlusMinus () {
    
}

void UIPlusMinus::moveTo(glm::vec3 p) {
    plus.moveTo(p * glm::vec3(0.8, 1.05, 1.0));
    minus.moveTo(p * glm::vec3(1.275, 1.05, 1.0));
    frame.moveTo(p);
}

void UIPlusMinus::scaleTo(glm::vec3 s) {
    plus.scaleTo(s);
    minus.scaleTo(s);
    frame.scaleTo(s);
}

void UIPlusMinus::setColour(glm::vec4 c) {
    plus.setColour(c);
    minus.setColour(c);
    
    frame.setColour(c);
}

void UIPlusMinus::setAlpha(GLfloat a) {
    plus.setAlpha(a);
    minus.setAlpha(a);
    
    frame.setAlpha(a);
}

void UIPlusMinus::activatePhysics   () { plus.activatePhysics(); minus.activatePhysics(); }
void UIPlusMinus::deactivatePhysics () { plus.deactivatePhysics(); minus.deactivatePhysics(); }

bool UIPlusMinus::isSelected() {
    return plus.isSelected() || minus.isSelected();
}

void UIPlusMinus::update (State state) {
    
    // PLUS
    if (mouse->leftButtonDown() && plus.isSelected()) {
        // increment counter
    }

    // MINUS
    if (mouse->rightButtonDown() && minus.isSelected()) {
        // decrement counter
    }
    
    
    // EFFECTS
    plus.isHidden = isHidden;
    minus.isHidden = isHidden;
    frame.isHidden = isHidden;
    
    if (isHidden) fadeOut();
    if (!isHidden) fadeIn();
    
    plus.update(state);
    minus.update(state);
    frame.update(state);
}

void UIPlusMinus::fadeIn() {
    plus.fadeIn();
    minus.fadeIn();
    frame.fadeIn();
}

void UIPlusMinus::fadeOut() {
    plus.fadeOut();
    minus.fadeOut();
    frame.fadeOut();
}
