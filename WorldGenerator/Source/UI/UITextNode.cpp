//
//  UITextNode.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "TextGeometry.hpp"
#include "UITextNode.hpp"

UITextNode::UITextNode (GraphicsEngine* graph) {
    graphics = new GraphicsObject (
        TextGeometry("hello"),
        Material("object")
    );
    
    graph->add(graphics);
    
    litColour = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);}

UITextNode::~UITextNode () {
    
}

void UITextNode::update () {
    
}

void UITextNode::fadeIn  () {
    
}

void UITextNode::fadeOut () {
    
}
