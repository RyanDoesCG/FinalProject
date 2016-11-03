/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/PlanetGraphics.hpp"

Planet::Planet  (Difficulty diff, long seed) {
    setGraphics (new PlanetGraphics());
//  setPhysics  (new PlanetPhysics());
    
    generateName();
    generateFlag();
}

Planet::~Planet () {

}

std::string Planet::toString() {
    std::string output = "";
    return output;
}

void Planet::randomise () {
    generateName();
    generateFlag();
}

void Planet::generateName() {
    const char* upperVowels = "AEIOU";
    const char* lowerVowels = "aeiou";
    const char* upperCons   = "BCDFGHJKLMNPQRSTVXZW";
    const char* lowerCons   = "bcdfghjklmnpqrstvxzw";
    int         length      = (rand() % 4) + 2;
    name = "";
    
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
}

void Planet::generateFlag() {
    galacticFlag = new Flag();
}

void Planet::generateBiomes () {

}
