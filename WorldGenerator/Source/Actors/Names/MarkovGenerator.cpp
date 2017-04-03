//
//  MarkovGenerator.cpp
//  MarkovNameMaker
//
//  Created by Ryan Needham on 28/03/2017.
//  Copyright © 2017 Ryan Needham. All rights reserved.
//

#include "MarkovGenerator.hpp"
#include "Letter.hpp"

std::vector<std::string> toppers = {
    "Prime", "Nova", "Maxim", "- X", "- Z",
    "Alpha", "Beta", "Gamma", "Delta", "Epsilon",
    "Zeta", "Eta", "Theta", "Iota", "Kappa", "Lambda",
    "Mu", "Nu", "Vu", "Xi", "Omicron", "Sigma", "Pi",
    "Tau", "Upsilon", "Phi", "Chi", "Psi", "Omega",
    "Major", "Minor"
};

std::string MarkovGenerator::generate(int length) {
    std::vector <Letter*> calculation;
    std::string output;
    
    // Start Value
    float v = rand() % 10;
    if (v > 5.0) calculation.push_back(new Vowel());
    else calculation.push_back(new Consonant());
    
    for (int i = 0; i < length; i++) {
        // vowel
        if (calculation.back()->type() == 1) {
            float v = rand() % 10;
            if (v > 5.0) calculation.push_back(new Vowel());
            else calculation.push_back(new Consonant());
        }
        
        // consonant
        if (calculation.back()->type() == 0) {
            float v = rand() % 10;
            if (v > 8.0) calculation.push_back(new Consonant());
            else calculation.push_back(new Vowel());
        }
    }
    
    // concatonate
    output += calculation.at(0)->value() - 32;
    for (int i = 1; i < length; i++)
        output += calculation.at(i)->value();
    
    // add a topper
    if (rand() % 10 > 6)
        output += " " + toppers.at(rand() % toppers.size());
    
    return output;
}
