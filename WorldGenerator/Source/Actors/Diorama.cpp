/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Diorama.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 31/01/2017.
 *  Copyright © 2017 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Diorama.hpp"

Diorama::Diorama() : base("base/base"), tree("trees/tree"), rock("trees/rock") {

    // main terrain
    surface = GridPlane(40, 40);
    surface.setColour(glm::vec3(0.96f, 0.87f, 0.70f));
    
    // base
    base.setShader("litObject", BASIC);
    base.setColour(glm::vec3(0.62f, 0.32f, 0.17f));
    base.setScale(30);
    base.setPosition(glm::vec3(10.0, -30, 10.0));
    
    // tree
    tree.setShader("litObject", BASIC);
    tree.setColour(glm::vec3(0.38, 0.42, 0.21));
    tree.setScale(0.64);
    
    for (int i = 0; i < 50; i++) {
        treeFlyweightTransforms.push_back(glm::vec3(rand() % 40, (rand() % 10) / 10, rand() % 40));
    }
    
    // rock
    rock.setShader("litObject", BASIC);
    rock.setColour(glm::vec3(0.86, 0.86, 0.86));
    rock.setScale(0.42);
    
    for (int i = 0; i < 50; i++) {
        rockFlyweightTransforms.push_back(glm::vec3(rand() % 40, 0.5 + ((rand() % 10) / 10), rand() % 40));
    }
}

Diorama::~Diorama () {
    
}

void Diorama::draw(SceneCamera *camera) {
    surface.draw(camera);
    base.draw(camera);
    
    for (int i = 0; i < 50; i++) {
        tree.setPosition(treeFlyweightTransforms.at(i));
        tree.update(RUNNING_FREEMODE);
        tree.draw(camera);
        
        rock.setPosition(rockFlyweightTransforms.at(i));
        rock.update(RUNNING_FREEMODE);
        rock.draw(camera);
    }
}

void Diorama::update(GameState state) {
    surface.update(state);
    base.update(state);
    
    tree.update(state);
}
