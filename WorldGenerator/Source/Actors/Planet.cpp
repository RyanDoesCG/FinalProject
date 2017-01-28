/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Planet.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"
#include "../../Headers/Engine/Utility/ColourPalette.hpp"
#include "../../Headers/Engine/Noise/NoiseInterface.hpp"
#include "../../Headers/FastNoise/FastNoise.h"

#include "../../Headers/GLFW/glfw3.h"

#include <math.h>

Planet::Planet ():  sphereRepresentation("sphere/sphereDETAILED"),

                    atmosphere("sphere/sphereDETAILED") {

    setColour(ColourPalette::getColour(Sand));
    
    sphereRepresentation.setShader("Planet", GEOM);
    sphereRepresentation.setScale(2);
                       
    water = Water();
                       
    atmosphere.setShader("Atmosphere", BASIC);
    atmosphere.setScale(2.1);
    atmosphere.setColour(glm::vec3(1.0, 0.0, 0.0));
                       
    generateName();
    
    sphereRepresentation.getShader()->update();
    glUniform1i(glGetUniformLocation(sphereRepresentation.getShader()->getProgramID(), "generationType"), 1);
                       
    /** 
     *  PARRALLELIZE?
     */
    FastNoise noise = FastNoise(rand());
    noise.SetFrequency(0.65);
    noise.SetFractalOctaves(2);
                       
    noise.SetCellularDistanceFunction(FastNoise::Euclidean);
                       
    // FMOD - roof
    // FABS - strip signing
                       
    // OCTAVE 1: LOW RES, HIGH AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.x = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 6);//NoiseInterface::getSimplexNoise(0.25, 2, i);
        sphereRepresentation.meshes.at(0).vertices.at(i).biome   = fabs(noise.GetCellular(pos.x, pos.y, pos.z) + 0.33);
    }
    
    noise.SetFrequency(6);
                       
    // OCTAVE 2: MEDIUM RES, MEDIUM AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.y = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 30);
    }

    noise.SetFrequency(12);
                       
    // OCTAVE 3: HIGH RES, MEDIUM AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.z = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 100);
    }
                       
    sphereRepresentation.meshes.at(0).updateModelMesh();
}

Planet::~Planet () {
    
}

void Planet::randomise () {
    sphereRepresentation.getShader()->update();
    glUniform1i(glGetUniformLocation(sphereRepresentation.getShader()->getProgramID(), "generationType"), 1 + (rand() % 4));
    sphereRepresentation.lightSource->setColour(glm::vec3(
        0.20 + (rand() % 40 / 10),
        0.20 + (rand() % 40 / 10),
        0.20 + (rand() % 40 / 10)
    ));
    
    atmosphere.setColour(glm::vec3(
        0.20 + (rand() % 20 / 10),
        0.20 + (rand() % 20 / 10),
        0.20 + (rand() % 20 / 10)
    ));
    
    FastNoise noise = FastNoise(rand());
    noise.SetFrequency(0.65);
    noise.SetFractalOctaves(2);
    
    noise.SetCellularDistanceFunction(FastNoise::Euclidean);
    
        // FMOD - roof
        // FABS - strip signing
    
        // OCTAVE 1: LOW RES, HIGH AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.x = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 6);//NoiseInterface::getSimplexNoise(0.25, 2, i);
        sphereRepresentation.meshes.at(0).vertices.at(i).biome   = fabs(noise.GetCellular(pos.x, pos.y, pos.z) + 0.33);
    }
    
    noise.SetFrequency(6);
    
        // OCTAVE 2: MEDIUM RES, MEDIUM AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.y = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 30);
    }
    
    noise.SetFrequency(12);
    
        // OCTAVE 3: HIGH RES, MEDIUM AMPLITUDE
    for (int i = 0; i < sphereRepresentation.meshes.at(0).vertices.size(); i++) {
        glm::vec3 pos = sphereRepresentation.meshes.at(0).vertices.at(i).position;
        sphereRepresentation.meshes.at(0).vertices.at(i).noise.z = fabs(noise.GetSimplexFractal(pos.x, pos.y, pos.z) / 100);
    }
    
    sphereRepresentation.meshes.at(0).updateModelMesh();
    
    generateName();
}

void Planet::setLight(Actor * light) {
    sphereRepresentation.setLightSource(light);
    water.setLightSource(light);
    atmosphere.setLightSource(light);
}

void Planet::draw (SceneCamera *camera) {
    water.getShader()->update();
    glUniform1f(glGetUniformLocation(water.getShader()->getProgramID(), "time"), glfwGetTime());
    
    glDisable(GL_CULL_FACE);
    sphereRepresentation.draw (camera);
    if (waterActive) water.draw  (camera);
    
    glDisable(GL_DEPTH_TEST);
    if (atmosActive) atmosphere.draw (camera);
    glEnable(GL_DEPTH_TEST);
}

void Planet::update (GameState state) {
    switch (state) {
        case MAIN_MENU: {
            sphereRepresentation.setRotation(glm::vec3(0.0, sphereRepresentation.getRotation().y + 0.0001, 0.0));
            sphereRepresentation.setPosition(glm::vec3(0.0, -1, 0.0));
            atmosphere.setPosition(glm::vec3(0.0, -1, 0.0));
            
//            water.setRotation(glm::vec3(0.0, water.getRotation().y + 0.00125, 0.0));
            water.setPosition(glm::vec3(0.0, -1, 0.0));
            break;
        }
        case RUNNING_FREEMODE: case RUNNING_EDITMODE: {
            //setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            sphereRepresentation.setPosition(glm::vec3(0.0, -1, 0.0));
            atmosphere.setPosition(glm::vec3(0.0, -1, 0.0));
            
//            water.setRotation(glm::vec3(0.0, water.getRotation().y + 0.00125, 0.0));
            water.setPosition(glm::vec3(0.0, -1, 0.0));
            break;
        }
    }
    
    sphereRepresentation.update(state);
    if (waterActive) water.update(state);
    if (atmosActive) atmosphere.update(state);
}

std::string Planet::getName() {return name;}

void Planet::generateName() {
    name = "";
    
    const char* upperVowels = "AEIOU";
    const char* lowerVowels = "aeiou";
    const char* upperCons   = "BCDFGHJKLMNPQRSTVXZW";
    const char* lowerCons   = "bcdfghjklmnpqrstvxzw";
    int         length = (rand() % 4) + 2;
    
    for (int i = 0; i < length; i++) {
        int ting = rand() % 100;
        
        if (i > 0) {
            if (ting < 36) name += lowerCons  [(rand() % 20)];
            else           name += lowerVowels[(rand() % 5)];
        }
        
        else {
            if (ting < 36) name += upperCons  [rand() % 20];
            else           name += upperVowels[rand() % 5];
        }
    }
    
    int ting = rand() % 200;
    
    if      (ting >= 0   && ting <= 24 ) name += " Alpha";
    else if (ting >= 25  && ting <= 49 ) name += " Beta";
    else if (ting >= 50  && ting <= 74 ) name += " Prime";
    else if (ting >= 75  && ting <= 99 ) name += "";
    else if (ting >= 100 && ting <= 124) name += "-Nova";
    else if (ting >= 125 && ting <= 149) name += "-Maxim";
    else if (ting >= 150 && ting <= 174) name += "-X";
    else if (ting >= 175 && ting <= 200) name += "s";
    
    std::cout << "NAME: " << name << std::endl;
}
