//
//  planetHUD.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "planetHUD.hpp"
#include "MarkovGenerator.hpp"

planetHUD::planetHUD  (GraphicsEngine* graph, PhysicsEngine* phys, Planet* p):
        GameHUD (graph, phys),
        metaData (graph, phys),
        amplitude(graph, phys),
        heightMap(graph, phys) {

        flag = new GraphicsObject (
            new QuadGeometry(),
            new Material(ShaderCache::loadBasicShader("flag"), std::string("flags/background_" + std::to_string(flagData.getID()) + ".png"))
        );
            
        name = MarkovGenerator::generate(2 + (rand() % 6));
            
        //amplitude.scaleTo(glm::vec3(1, 1, 1));
        
            
            metaData.scaleTo(glm::vec3(1.25, 0.25, 1.0));
            metaData.moveTo(glm::vec3(-2.075, 0.6, 0));
            
        heightMap.scaleTo(glm::vec3(1.25, 0.25, 1.0));
        heightMap.moveTo(glm::vec3(-2.075, 0, 0));
        
        amplitude.moveTo(glm::vec3(-2.075, -0.6, 0));
        // graph->add(flag);
        planet = p;
            
        flag->scale = glm::vec3(1, 0.5, 0.25);
        flag->position = glm::vec3(-2, 1.2, 0.1);
        flag->colour = flagData.getColour();
            
        graph->addToUI(flag);
            
        engine = graph;

}

planetHUD::~planetHUD () {}

void planetHUD::hide () {
    background.isHidden = true;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->deactivatePhysics();
        box->isHidden = true;
    });
    
    
    amplitude.deactivatePhysics();
    amplitude.isHidden = true;
    
    heightMap.deactivatePhysics();
    heightMap.isHidden = true;
    
    metaData.deactivatePhysics();
    metaData.isHidden = true;
    
    if (flag->colour.a > 0)
        flag->colour.a -= 0.2;
    
}

void planetHUD::show () {
    background.isHidden = false;
    
    for_each(items.begin(), items.end(), [](UIBox* box) {
        box->activatePhysics();
        box->isHidden = false;
    });
    
    
    amplitude.activatePhysics();
    amplitude.isHidden = false;
    
    heightMap.activatePhysics();
    heightMap.isHidden = false;
    
    metaData.activatePhysics();
    metaData.isHidden = false;
    
    if (flag->colour.a < 1)
        flag->colour.a += 0.2;
}

void planetHUD::update (State state) {
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
        planet->changeHeightMap();
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
    
    planet->setAmplitude (amplitude.getValue() * 0.05);
}
