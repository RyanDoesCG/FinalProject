//
//  dioramaHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "dioramaHUD.hpp"
#include "ShaderCache.hpp"
#include "QuadGeometry.hpp"

dioramaHUD::dioramaHUD  (GraphicsEngine* graph, PhysicsEngine* phys, Diorama* d):
    flag           (new QuadGeometry(), new Material(ShaderCache::loadBasicShader("object_textured"))),
    GameHUD        (graph, phys),
    renderDistance (graph, phys),
    amplitude      (graph, phys),
    seaLevel       (graph, phys),
    example3       (graph, phys) {
    
    //amplitude.scaleTo(glm::vec3(1, 1, 1));
    renderDistance.moveTo(glm::vec3(-2, 0.75, 0.1));
    amplitude.moveTo(glm::vec3(-2, 0.25, 0.1));
    seaLevel.moveTo(glm::vec3(-2, -0.25, 0.1));
    example3.moveTo(glm::vec3(-2, -0.75, 0.1));
    
   // graph->add(flag);
    diorama = d;
        
    engine = graph;
}

dioramaHUD::~dioramaHUD () {}

void dioramaHUD::hide () {
    background.isHidden = true;
    
    for_each(items.begin(), items.end(), [] (UIBox* box) {
        box->deactivatePhysics();
        //box->setAlpha(0);
        box->isHidden = true;
    });
    
    renderDistance.deactivatePhysics();
    renderDistance.isHidden = true;
    
    amplitude.deactivatePhysics();
    amplitude.isHidden = true;
    
    seaLevel.deactivatePhysics();
    seaLevel.isHidden = true;
    
    example3.deactivatePhysics();
    example3.isHidden = true;
    
}

void dioramaHUD::show () {
    background.isHidden = false;
    
    for_each(items.begin(), items.end(), [] (UIBox* box) {
        box->activatePhysics();
        //box->setAlpha(1);
        box->isHidden = false;
    });
    
    renderDistance.activatePhysics();
    renderDistance.isHidden = false;

    amplitude.activatePhysics();
    amplitude.isHidden = false;
    
    seaLevel.activatePhysics();
    seaLevel.isHidden = false;
    
    example3.activatePhysics();
    example3.isHidden = false;

}

void dioramaHUD::update (State state) {
    background.update(state);
    
    if (items.front()->isHidden == false ) {
        engine->addToText("render distance",   glm::vec2(-668,  160), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("terrain amplitude", glm::vec2(-668,   10), 0.24, glm::vec3(0.64, 0.64, 0.64));
        
        engine->addToText("back", glm::vec2(-668,  -418), 0.24, glm::vec3(0.64, 0.64, 0.64));
    }
    
    for (UIBox* box : items) {
        box->update(state);   
    }
    
    renderDistance.update(state);
    amplitude.update(state);
    seaLevel.update(state);
    example3.update(state);
    
    diorama->setRenderDistance (renderDistance.getValue() * 1.53);
    diorama->setAmplitude      (amplitude.getValue() * 0.05);
    diorama->setSeaLevel       (seaLevel.getValue() * 0.25);
}
