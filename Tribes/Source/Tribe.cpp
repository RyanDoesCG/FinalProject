/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Tribe.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Tribe.hpp"

Tribe::Tribe() {
    ethos      = static_cast<Ethos>(rand() % ETHOS_MAX);
    population = (rand() % 100000) + 1;
    
    generateName();
    generateFlag();
}

Tribe::~Tribe() {

}

/** 
 *  Make this better
 *
 *      - Different lexican for each ethos?
 *          - reflect education levels in lexican?
 *
 *      - Aggressive capitalisation for warriors?
 */
void Tribe::generateName() {
    const char* upperVowels = "AEIOU";
    const char* lowerVowels = "aeiou";
    const char* upperCons   = "BCDFGHJKLMNPQRSTVXZW";
    const char* lowerCons   = "bcdfghjklmnpqrstvxzw";
    int         length      = (rand() % 11) + 2;
    
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
}

/** 
 *  select from a group of "themes" based on ethos
 *      - bones, weapons etc. for warriors
 *      - atoms, lab equipment etc. for scientists
 *      - religious artifacts for preachers
 *      - planet/travel/money stuff for traders
 *      - Ferals have a big X on a plain background
 */
void Tribe::generateFlag() {
    // 1200 x 720
    switch (ethos) {
        case Warriors:
            break;
        case Scientists:
            break;
        case Preachers:
            break;
        case Traders:
            break;
        case Ferals:
            break;
    }
}

std::string Tribe::getName () {
    std::cout << "fucking broken" << "\n";
    return "";
}

Ethos Tribe::getEthos () {
    return this->ethos;
}

Texture* Tribe::getFlag () {
    return flag;
}

int Tribe::getPopulation () {
    return this->population;
}

std::string Tribe::toString() {
    std::string output = "";
    
    output += "Name:       ";
    output += this->name;
    output += "\n";
    
    output += "Ethos:      ";
    if      (ethos == Warriors)   output += "Warriors";
    else if (ethos == Scientists) output += "Scientists";
    else if (ethos == Traders)    output += "Traders";
    else if (ethos == Preachers)  output += "Preachers";
    else if (ethos == Ferals)     output += "Ferals";
    output += "\n";

    output += "Population: ";
    output += std::to_string(population);
    output += "\n";
    
    return output;
}
