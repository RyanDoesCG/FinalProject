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

const int width = 40;
const int height = 40;

GLfloat data[width*10][height*10] = {};

Diorama::Diorama() : base("base/base"), tree("trees/tree"), rock("trees/rock") {
    
    biome = Biome();
    
    // Init Noise Machine
    noiseMachine = FastNoise(rand());
    
    /** 
     * Terrain Generation
     */
    surface = GridPlane(width, height);
    surface.setColour(biome.getPrimaryColour());
    
    generateHeightMap();
    generateDipMap();
    
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

/** 
 *  generateHeightMap
 *
 *  Writes a series of noise values to a texture for the
 *  vertex shader.
 */
void Diorama::generateHeightMap () {
    for (int i = 0; i < width*10; i++) {
        for (int j = 0; j < height*10; j++) {
            data[i][j] = 0.5f;
            //std::cout << data[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    glGenTextures(1, &heightMapTextureID);
    glBindTexture(GL_TEXTURE_2D, heightMapTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE_FLOAT32_ATI, width * 10, height * 10, 0, GL_LUMINANCE, GL_FLOAT, data);
}

/**
 *  generateDipMap
 *
 *  Writes a series of noise values to a texture for the
 *  vertex shader.
 */
void Diorama::generateDipMap () {
    
}

void Diorama::draw(SceneCamera *camera) {

    //glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, heightMapTextureID);
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
