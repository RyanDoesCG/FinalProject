/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Planet.hpp"

Planet::Planet  (Difficulty difficulty) {
    srand(static_cast<unsigned int>(time(0)));
    
    this->difficulty = difficulty;
    this->biomeCount = rand() % ((difficulty + 1) * 10); // the fuck?
    this->tribeCount = rand() % ((difficulty + 1) * 10);
    
    regions = new std::vector<Biome*>();
    tribes  = new std::vector<Tribe*>();

    for (int i = 0; i < biomeCount; i++) regions->push_back(new Biome());
    for (int i = 0; i < tribeCount; i++) tribes ->push_back(new Tribe());
}

Planet::~Planet () {
    // free each element
    for (int i = 0; i < biomeCount; i++) free(&regions[i]);
    for (int i = 0; i < tribeCount; i++) free(&tribes[i]);
    
    // free collections
    free(regions);
    free(tribes);
}

std::string* Planet::toString() {
    std::string* output = new std::string();
    
    std::cout << "difficulty:  " << this->getDifficulty() << "\n";
    std::cout << "biome count: " << this->getBiomeCount() << "\n";
    for (int i = 0; i < regions->size(); i++) regions->at(i)->toString();
    std::cout << "tribe count: " << this->getTribeCount() << "\n";
    for (int i = 0; i < tribes->size(); i++) tribes->at(i)->toString();
    
    return output;
}
