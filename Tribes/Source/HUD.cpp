/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 05/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUD.hpp"

#include "../Headers/Engine/TextRenderingComponent.hpp"
#include "../Headers/Engine/IndexedMeshComponent.hpp"
#include "../Headers/Engine/ShaderComponent.hpp"

HUD::HUD  () {

}

HUD::~HUD () {

}

void HUD::init () {
    addComponent(new TextRenderingComponent());
}

void HUD::update () {

    dynamic_cast<TextRenderingComponent*>(components.at(0))->renderTextAs2D("pre-alpha", glm::vec2(5, 5), 0.5);
    
    Actor::update();
}
