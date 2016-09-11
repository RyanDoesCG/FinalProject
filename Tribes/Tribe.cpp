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
    
        population = (rand() % 1000) + 1;
}

Tribe::~Tribe () {

}

void Tribe::generateName() {
    // ISSUE: Picking Garbage
    
    char upperVowels[] = {'A', 'E', 'I', 'O', 'U'};
    char lowerVowels[] = {'a', 'e', 'i', 'o', 'u'};
    char upperCons  [] = {'B', 'C', 'D', 'F', 'G',
                          'H', 'J', 'K', 'L', 'M',
                          'N', 'P', 'Q', 'R', 'S',
                          'T', 'V', 'X', 'Z', 'W'};
    char lowerCons  [] = {'b', 'c', 'd', 'f', 'g',
                          'h', 'j', 'k', 'l', 'm',
                          'n', 'p', 'q', 'r', 's',
                          't', 'v', 'x', 'x', 'w'};
    
    int  length = rand() % 14;
    char name[length];
    
    for (int i = 0; i < length; i++) {
        int ting = rand() % 100;
        
        if (i > 0) {
            if (ting < 36) {
                name[i] = lowerCons[(rand() % 18) + 1];
            } else {
                name[i] = lowerVowels[(rand() % 4) + 1];
            }
        }
        
        else {
            if (ting < 36) {
                name[i] = upperCons[rand() % 18];
            } else {
                name[i] = upperVowels[rand() % 4];
            }
        }
    }
    
    // TEMP FIX: kull numbers (find cause)
    for (int i; i < length; i++) if (name[i] == '\\' || name[i] == '_') name[i] = ' ';
    
    /*
     
     Sample
     
     Ocjc\377
     Ioiljkim\343+
     Avxaeoroie
     Aaias
     \240\361\277_\377
     Egooeiare+
     Eqaeiiiimieii
     Hpim\377
     Ailaaie
     E\361\277_\377
     Eabla
     Pehiilaomi
     Eiorise
     \240\361\277_\377
     
     */
    
    this->name = name;
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
    } else if (ethos == Ferals) {
        output += "Ferals\n";
    }
    
    return this->name;
}