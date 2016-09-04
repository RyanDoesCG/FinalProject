/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.cpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Biome.hpp"

Biome::Biome  () {
    srand(static_cast<unsigned int>(time(0)));
    this->weather = static_cast<Weather>(rand() % (WEATHER_MAX) + 1);
    this->landscape = static_cast<Landscape>(rand() % (LANDSCAPE_MAX) + 1);
    this->vegitation = static_cast<Vegitation>(rand() % (VEGITATION_MAX) + 1);
}


Biome::~Biome () {

}

std::string Biome::toString() {
    std::string output = "Weather: ";
    if      (weather == 1) output += "Snow\n";
    else if (weather == 2) output += "Desert\n";
    else if (weather == 3) output += "Normal\n";
    
    output += "Landscape: ";
    if      (landscape == 1) output += "Mountainous\n";
    else if (landscape == 2) output += "Flatlands\n";
    else if (landscape == 3) output += "Hilly\n";
    
    output += "Vegitation: ";
    if      (vegitation == 1) output += "Plentiful\n";
    else if (vegitation == 2) output += "Moderate\n";
    else if (vegitation == 3) output += "Sparse\n";
    return output;
}
