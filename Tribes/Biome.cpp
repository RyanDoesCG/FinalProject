/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.cpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Biome.hpp"

Biome::Biome () {
    srand(static_cast<unsigned int>(time(0)));
    this->weather = static_cast<Weather>(rand() % (WEATHER_MAX));
    this->landscape = static_cast<Landscape>(rand() % (LANDSCAPE_MAX));
    this->vegitation = static_cast<Vegitation>(rand() % (VEGITATION_MAX));
    
    // meh...
    this->hospitability = (weather + landscape + vegitation) * 10;
}


Biome::~Biome () {

}

inline Weather Biome::getWeatherType () { return weather; }
inline Landscape Biome::getLandscapeType () { return landscape; }
inline Vegitation Biome::getVegitationType () { return vegitation; }

std::string Biome::toString() {
    std::string output = "Weather: ";
    if      (weather == Snow) output += "Snow\n";
    else if (weather == Desert) output += "Desert\n";
    else if (weather == Normal) output += "Normal\n";
    
    output += "Landscape: ";
    if      (landscape == Mountainous) output += "Mountainous\n";
    else if (landscape == Flatlands) output += "Flatlands\n";
    else if (landscape == Hilly) output += "Hilly\n";
    
    output += "Vegitation: ";
    if      (vegitation == Plentiful) output += "Plentiful\n";
    else if (vegitation == Moderate) output += "Moderate\n";
    else if (vegitation == Sparse) output += "Sparse\n";
    
    output += "Hospitability: ";
    output += std::to_string(hospitability);
    output += "\n";
    return output;
}
