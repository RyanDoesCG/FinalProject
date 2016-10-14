/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/PlanetGraphics.hpp"

Planet::Planet  (Difficulty diff, long seed) {
    setGraphics (new PlanetGraphics());
//  setPhysics  (new PlanetPhysics());

    
    difficulty = diff;
    biomeCount = ((difficulty + 1) * 5) + (rand() % 10);
    tribeCount = ((difficulty + 1) * 3) + (rand() % 10);
    
    regions = std::vector<Biome*>();
    tribes  = std::vector<Tribe*>();

    for (int i = 0; i < biomeCount; i++) regions.push_back(new Biome());
    for (int i = 0; i < tribeCount; i++) tribes.push_back(new Tribe());
}

Planet::~Planet () {
    // free each element
    for (int i = 0; i < biomeCount; i++) free(regions[i]);
    for (int i = 0; i < tribeCount; i++) free(tribes[i]);
}

std::string Planet::toString() {
    std::string output = "";
    
    // difficulty
    output += "difficulty:  ";
    if      (difficulty == TOUGH)    output += "TOUGH\n";
    else if (difficulty == TOUGHER)  output += "TOUGHER\n";
    else if (difficulty == TOUGHEST) output += "TOUGHEST\n";
    
    // biomes
    output += "biome count: ";
    output += std::to_string(this->getBiomeCount()); output += "\n";
    for (int i = 0; i < regions.size(); i++) std::cout << "\n" << regions[i]->toString();
    
    // tribes
    output += "tribe count: ";
    output += std::to_string(this->getTribeCount()); output += "\n";
    for (int i = 0; i < tribes.size(); i++) std::cout << "\n" << tribes[i]->toString();
    
    return output;
}
