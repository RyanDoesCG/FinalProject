/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.cpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Biome.hpp"

Biome::Biome () {
    srand(static_cast<unsigned int>(time(0)));
    this->weather       = static_cast<Weather>   (rand() % WEATHER_MAX);
    this->landscape     = static_cast<Landscape> (rand() % LANDSCAPE_MAX);
    this->vegitation    = static_cast<Vegitation>(rand() % VEGITATION_MAX);
    this->mainResource  = static_cast<Resources> (rand() % RESOURCE_MAX);
    this->auxResource   = static_cast<Resources> (rand() % RESOURCE_MAX);
    
    // ensure no duplicate resource types
    while (auxResource == mainResource) {
        this->auxResource = static_cast<Resources>(rand() % RESOURCE_MAX);
    }
}


Biome::~Biome () {

}

inline Weather    Biome::getWeatherType       () { return weather; }
inline Landscape  Biome::getLandscapeType     () { return landscape; }
inline Resources  Biome::getMainResourcesType () { return mainResource; }
inline Resources  Biome::getAuxResourcesType  () { return auxResource; }
inline Vegitation Biome::getVegitationType    () { return vegitation; }

std::string Biome::toString() {
    std::string output = "Weather: ";
    if      (weather == Snow)     output += "Snow\n";
    else if (weather == Desert)   output += "Desert\n";
    else if (weather == Normal)   output += "Normal\n";
    else if (weather == Volcanic) output += "Volcanic\n";
    
    output += "Landscape: ";
    if      (landscape == Mountainous) output += "Mountainous\n";
    else if (landscape == Flatlands)   output += "Flatlands\n";
    else if (landscape == Hilly)       output += "Hilly\n";
    
    output += "Vegitation: ";
    if      (vegitation == Plentiful) output += "Plentiful\n";
    else if (vegitation == Moderate)  output += "Moderate\n";
    else if (vegitation == Sparse)    output += "Sparse\n";
    
    output += "Main Resources: ";
    if      (mainResource == Bronze)     output += "Bronze\n";
    else if (mainResource == Iron)       output += "Iron\n";
    else if (mainResource == Steel)      output += "Steel\n";
    else if (mainResource == Alluminium) output += "Alluminium\n";
    else if (mainResource == Diamond)    output += "Diamond\n";
    
    output += "Auxiliary Resources: ";
    if      (auxResource == Bronze)     output += "Bronze\n";
    else if (auxResource == Iron)       output += "Iron\n";
    else if (auxResource == Steel)      output += "Steel\n";
    else if (auxResource == Alluminium) output += "Alluminium\n";
    else if (auxResource == Diamond)    output += "Diamond\n";

    output += "\n\n";
    return output;
}
