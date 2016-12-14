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

#include "../../Headers/GLFW/glfw3.h"

Planet::Planet (): Model("sphere/sphere"),
                   water("sphere/sphereDETAILED"),
                   atmosphere("sphere/sphereDETAILED") {

    setColour(ColourPalette::getColour(Sand));
    
    setShader("Planet", GEOM);
    setScale(1.2);
    
    water.setShader("water", GEOM);
    water.setScale(0.94);
    water.setRotation(glm::vec3(0.15, 0.23, 0));
                       
    atmosphere.setShader("Atmosphere", BASIC);
    atmosphere.setScale(1.025);
    atmosphere.setColour(glm::vec3(1.0, 0.0, 0.0));
                       
    generateName();
    
    getShader()->update();
    glUniform1i(glGetUniformLocation(getShader()->getProgramID(), "generationType"), 1);

}

Planet::~Planet () {
    
}

void Planet::randomise () {
    getShader()->update();
    glUniform1i(glGetUniformLocation(getShader()->getProgramID(), "generationType"), 1 + (rand() % 4));
    lightSource->setColour(glm::vec3(
        0.20 + (rand() % 60 / 10),
        0.20 + (rand() % 60 / 10),
        0.20 + (rand() % 60 / 10)
    ));
    
    generateName();
}

void Planet::setLight(Actor * light) {
    this->setLightSource(light);
    water.setLightSource(light);
    atmosphere.setLightSource(light);
}

void Planet::draw (SceneCamera *camera) {
    water.getShader()->update();
    glUniform1f(glGetUniformLocation(water.getShader()->getProgramID(), "time"), glfwGetTime());
    
    Model::draw     (camera);
    water.draw      (camera);
    
    glDisable(GL_DEPTH_TEST);
    atmosphere.draw (camera);
    glEnable(GL_DEPTH_TEST);
}

void Planet::update (GameState state) {
    switch (state) {
        case MAIN_MENU: {
            setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            setPosition(glm::vec3(0.0, 0.0, 0.0));
            
            water.setRotation(glm::vec3(0.0, water.getRotation().y + 0.00125, 0.0));
            water.setPosition(glm::vec3(0.0, 0.0, 0.0));
            
            atmosphere.setRotation(glm::vec3(0.0, 0, 0.0));
            atmosphere.setPosition(glm::vec3(0.0, 0.0, 0.0));
            break;
        }
        case RUNNING_FREEMODE: case RUNNING_EDITMODE: {
            setRotation(glm::vec3(0.0, getRotation().y + 0.001, 0.0));
            setPosition(glm::vec3(0.0, 0.0, 0.0));
            
            water.setRotation(glm::vec3(0.0, water.getRotation().y + 0.00125, 0.0));
            water.setPosition(glm::vec3(0.0, 0.0, 0.0));
            
            atmosphere.setRotation(glm::vec3(0.0, 0, 0.0));
            atmosphere.setPosition(glm::vec3(0.0, 0.0, 0.0));
            break;
        }
    }
    
    Model::update(state);
    water.update(state);
    atmosphere.update(state);
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
