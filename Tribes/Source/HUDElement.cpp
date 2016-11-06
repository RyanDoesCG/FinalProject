/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUDElement.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 06/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUDElement.hpp"

HUDElement::HUDElement  (std::string t, glm::vec2 p) {
    selected = 0;
    position = p;
    text = t;
    
    box = {
    //   x     y    z     x     y    z     x      y    z
        -0.95, 0.9, 0.0, -0.25, 0.9, 0.0, -0.25, -0.9, 0.0, // TRIANGLE 1
        -0.95, 0.9, 0.0, -0.95, -0.9, 0.0, -0.25, -0.9, 0,0// TRIANGLE 2
    };
}

HUDElement::~HUDElement () {

}

void HUDElement::init () {
    textRenderer = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    shader = (ShaderComponent*)addComponent(new ShaderComponent("HUDPane"));
    mesh = (MeshComponent*)addComponent(new MeshComponent());
}

void HUDElement::update (GameState state) {
    // send text render calls
    if (selected)
        textRenderer->renderTextAs2D(text, position, glm::vec3(0.94, 0.94, 0.94), 0.54);
    else
        textRenderer->renderTextAs2D(text, position, glm::vec3(0.08, 0.08, 0.08), 0.48);
    
    // upload selected uniform to GPU
    shader->update();
    glUniform1i(glGetUniformLocation(shader->getProgramID(), "selected"), selected);
    
    // call super
    Actor::update(state);
}

void HUDElement::select () { selected = 1; }
void HUDElement::unselect () { selected = 0;}
