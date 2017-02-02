/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Diorama.cpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 31/01/2017.
 *  Copyright © 2017 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Diorama.hpp"

const int width = 40;
const int height = 40;

GLubyte heightMap [width*10] [height*10] [3]; // r = octave 1, g = octave 2, b = octave 3
GLubyte dipMap    [width*10] [height*10] [3]; // 1 value, drop level

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
    tree.setShader("litObject", BASIC);
    tree.setColour(biome.getSecondaryColour());
    tree.setScale(0.64);
    for (int i = 0; i < height; i++)
        treeFlyweightTransforms.push_back(glm::vec3(rand() % width, (rand() % 10) / 10, rand() % width));
    
    // rock
    rock.setShader("litObject", BASIC);
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
    for (int x = 0; x < width*10; x++) {
        for (int y = 0; y < height*10; y++) {
            float amplitude;
            
            // write majorly (only?) positive values
            // for form mountains etc.
            noiseMachine.SetFrequency(2);
            amplitude = 20;
            heightMap[x][y][0] = static_cast<GLubyte>(noiseMachine.GetSimplex(x, y) / amplitude * 255.f);  // low frequency, high amplitude
            
            noiseMachine.SetFrequency(6);
            amplitude = 5;
            heightMap[x][y][0] = static_cast<GLubyte>(noiseMachine.GetSimplex(x, y) / amplitude * 255.f);    // medium frequency, medium amplitude
            
            noiseMachine.SetFrequency(12);
            amplitude = 2;
            heightMap[x][y][0] = static_cast<GLubyte>(noiseMachine.GetSimplex(x, y) / amplitude * 255.f);    // high frequency, low amplitude
        }
    }
    
    glGenTextures   (1, &heightMapTexture);
    glBindTexture   (GL_TEXTURE_2D, heightMapTexture);
    glTexImage2D    (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, heightMap);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture   (GL_TEXTURE_2D, 0);
}

/**
 *  generateDipMap
 *
 *  Writes a series of noise values to a texture for the
 *  vertex shader.
 */
void Diorama::generateDipMap () {

    
    for (int x = 0; x < width*10; x++) {
        for (int y = 0; y < height*10; y++) {
            
            // write negative values to give water areas
            dipMap[x][y][0] = 0.0f;
            dipMap[x][y][1] = 0.0f;
            dipMap[x][y][2] = 0.0f;
        }
    }
}

void Diorama::draw(SceneCamera *camera) {

    glBindTexture(GL_TEXTURE_2D, heightMapTexture);
        surface.draw(camera);
    glBindTexture(GL_TEXTURE_2D, 0);
    
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
