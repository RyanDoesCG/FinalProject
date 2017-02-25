/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Diorama.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 31/01/2017.
 *  Copyright © 2017 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Diorama.hpp"
#include "../../Headers/soil/SOIL.h"
#include "../../Headers/Engine/Noise/HeightMap.hpp"

const int width = 100;
const int height = 100;

Diorama::Diorama() : base("base/base"), tree("trees/tree"), rock("trees/rock"), landscape(width * 10, height * 10), waterscape(width * 10, height * 10) {
    
    biome = Biome();
    
    // Init Noise Machine
    noiseMachine = FastNoise(rand());
    
    /** 
     * Terrain Generation
     */
    surface = GridPlane(width, height);
    surface.setColour(biome.getPrimaryColour());
    
    // base
    base.setShader("litObject", BASIC);
    base.setColour(biome.getMountainColour());
    base.setScale(height * 0.75);
    base.setPosition(glm::vec3(height * 0.25, (height * 0.76) * -1, height * 0.25));
    
    // tree
    tree.setShader("proceduralGen", BASIC);
    tree.setColour(biome.getSecondaryColour());
    tree.setScale(0.64);
    for (int i = 0; i < height; i++)
        treeFlyweightTransforms.push_back(glm::vec3(rand() % width, (rand() % 10) / 10, rand() % width));
    
    // rock
    rock.setShader("proceduralGen", BASIC);
    rock.setColour(glm::vec3(0.50, 0.50, 0.50));
    rock.setScale(0.42);
    for (int i = 0; i < height; i++)
        rockFlyweightTransforms.push_back(glm::vec3(rand() % width, 0.5 + ((rand() % 10) / 10), rand() % width));
}

Diorama::~Diorama () {
    
}

void Diorama::draw(SceneCamera *camera) {

    surface.updateShader();
    landscape.bind();
    surface.draw(camera);
    
    base.draw(camera);
    
    for (int i = 0; i < treeFlyweightTransforms.size(); i++) {
        tree.setPosition(treeFlyweightTransforms.at(i));
        tree.update(RUNNING_FREEMODE);
        tree.draw(camera);
    }
    
    for (int i = 0; i < rockFlyweightTransforms.size(); i++) {
        rock.setPosition(rockFlyweightTransforms.at(i));
        rock.update(RUNNING_FREEMODE);
        rock.draw(camera);
    }
}

void Diorama::update(GameState state) {
    surface.update(state);
    base.update(state);
}
