/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUDElement.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 06/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/HUDElement.hpp"
#include "../Headers/Engine/ShaderCache.hpp"

HUDElement::HUDElement  (std::string t, glm::vec2 p) {
    selected = 0;
    position = p;
    text     = t;
}

HUDElement::~HUDElement () {

}

void HUDElement::init () {
    textRenderer = (TextRenderingComponent*)addComponent(new TextRenderingComponent());
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("HUDPane"));
}

void HUDElement::update (GameState state, SceneCamera* camera) {
    // send text render calls
    if (selected)
        textRenderer->renderTextAs2D(text, position, glm::vec3(0.94, 0.94, 0.94), 0.54);
    else
        textRenderer->renderTextAs2D(text, position, glm::vec3(0.08, 0.08, 0.08), 0.48);
    
    // upload selected uniform to GPU
    shader->update();
    glUniform1i(glGetUniformLocation(shader->getProgramID(), "selected"), selected);
    
    // call super
    Actor::update(state, camera);
}

void HUDElement::select () { selected = 1; }
void HUDElement::unselect () { selected = 0;}
