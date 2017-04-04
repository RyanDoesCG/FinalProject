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
    GameHUD        (graph, phys),
    metaData(graph, phys),
    amplitude      (graph, phys),
    heightMap      (graph, phys) {
    
    flag = new GraphicsObject (
        new QuadGeometry(),
        new Material(ShaderCache::loadBasicShader("flag"), std::string("flags/background_" + std::to_string(flagData.getID()) + ".png"))
    );
    
    name = MarkovGenerator::generate(2 + (rand() % 6));
    
        metaData.scaleTo(glm::vec3(1.25, 0.25, 1.0));
        metaData.moveTo(glm::vec3(-2.075, 0.6, 0));
        
        heightMap.scaleTo(glm::vec3(1.25, 0.25, 1.0));
        heightMap.moveTo(glm::vec3(-2.075, 0, 0));
        
        amplitude.moveTo(glm::vec3(-2.075, -0.6, 0));
        
    diorama = d;
    
    flag->scale = glm::vec3(1, 0.5, 0.25);
    flag->position = glm::vec3(-2, 1.2, 0.1);
    flag->colour = flagData.getColour();
    
    graph->addToUI(flag);
    
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
    
    amplitude.deactivatePhysics();
    amplitude.isHidden = true;
    
    heightMap.deactivatePhysics();
    heightMap.isHidden = true;
    
    metaData.deactivatePhysics();
    metaData.isHidden = true;
    
    flag->colour.a = 0;
    
}

void dioramaHUD::show () {
    background.isHidden = false;
    
    for_each(items.begin(), items.end(), [] (UIBox* box) {
        box->activatePhysics();
        //box->setAlpha(1);
        box->isHidden = false;
    });
    
    amplitude.activatePhysics();
    amplitude.isHidden = false;
    
    heightMap.activatePhysics();
    heightMap.isHidden = false;
    
    metaData.activatePhysics();
    metaData.isHidden = false;

    if (flag->colour.a < 1)
        flag->colour.a += 0.5;
    
}

void dioramaHUD::update (State state) {
    background.update(state);
    
    if (items.front()->isHidden == false ) {
        engine->addToText(name,                 glm::vec2(-672, 280), 0.24, glm::vec3(1.0, 1.0, 1.0));
        engine->addToText("<   meta data    >", glm::vec2(-685,  180), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("<   height map   >", glm::vec2(-685,  -10), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("terrain amplitude",  glm::vec2(-685,   -270), 0.24, glm::vec3(0.64, 0.64, 0.64));
        engine->addToText("back",               glm::vec2(-672,  -414), 0.24, glm::vec3(0.64, 0.64, 0.64));
    }
    
    for (UIBox* box : items) {
        box->update(state);   
    }
    
    if (heightMap.isClicked()) {
        diorama->changeHeightMap();
    }
    
    // LEAK
    if (metaData.isClicked()) {
        name = MarkovGenerator::generate(rand() % 10);
        flag->material = new Material(ShaderCache::loadBasicShader("flag"), std::string("flags/background_" + std::to_string(Flag().getID()) + ".png"));
        flag->colour = Flag().getColour();
    }
    
    amplitude.update(state);
    heightMap.update(state);
    metaData.update(state);
    
    diorama->setAmplitude      (amplitude.getValue() * 0.05);
    //diorama->setSeaLevel       (seaLevel.getValue() * 0.25);
}
