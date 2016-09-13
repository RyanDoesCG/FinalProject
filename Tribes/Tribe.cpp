/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Tribe.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Tribe.hpp"

Tribe::Tribe  () {
        ethos = static_cast<Ethos>(rand() % ETHOS_MAX);
    
        generateName();
        generateFlag();
    
        population = (rand() % 100000) + 1;
}

Tribe::~Tribe () {

}

void Tribe::generateName() {
    const char* upperVowels = "AEIOU";
    const char* lowerVowels = "aeiou";
    const char* upperCons   = "BCDFGHJKLMNPQRSTVXZW";
    const char* lowerCons   = "bcdfghjklmnpqrstvxzw";
    
    int  length = (rand() % 15) + 2;
    
    for (int i = 0; i < length; i++) {
        int ting = rand() % 100;
        
        if (i > 0) {
            if (ting < 36)
                name += lowerCons[(rand() % 20)];
            else
                name += lowerVowels[(rand() % 5)];
        }
        
        else {
            if (ting < 36)
                name += upperCons[rand() % 20];
            else
                name += upperVowels[rand() % 5];
        }
    }
}

void Tribe::generateFlag() {
    
    
}

std::string Tribe::toString() {
    std::string output = "";
    
    output += "Name: ";
    output += this->name;
    output += "\n";
    
    output += "Ethos: ";
    if (ethos == Warriors) {
        output += "Warriors\n";
    } else if (ethos == Scientists) {
        output += "Scientists\n";
    } else if (ethos == Traders) {
        output += "Traders\n";
    } else if (ethos == Preachers) {
        output += "Preachers\n";
    } else if (ethos == Ferals) {
        output += "Ferals\n";
    }
    
    output += "Population: ";
    output += std::to_string(population);
    output += "\n";
    
    return output;
}