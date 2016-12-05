//
//  Renderer.cpp
//  Tribes
//
//  Created by user on 05/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Renderer.hpp"

Renderer::Renderer (Player* p) {
    player = p;
}

Renderer::~Renderer () {
    
}

void Renderer::addToScene(Actor* actor) {
    scene.push_back(actor);
}

void Renderer::drawScene(GameState state) {
    for (int i = 0; i < scene.size(); i++) {
        scene.at(i)->update(state, player->getView());
    }
}
