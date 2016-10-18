/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.cpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Biome.hpp"

Biome::Biome () {
    weather      = static_cast<Weather>   (rand() % WEATHER_MAX);
    landscape    = static_cast<Landscape> (rand() % LANDSCAPE_MAX);
    vegitation   = static_cast<Vegitation>(rand() % VEGITATION_MAX);
    mainResource = static_cast<Resources> (rand() % RESOURCE_MAX);
    auxResource  = static_cast<Resources> (rand() % RESOURCE_MAX);
    
    // ensure no duplicate resource types
    while (auxResource == mainResource) {
        auxResource = static_cast<Resources>(rand() % RESOURCE_MAX);
    }
    
    this->setGraphics(new GraphicsComponent()); // needs to be specific for a biome.
}

Biome::~Biome () {

}

/** 
 *  getWeatherType
 *
 *  @returns Weather    The value of the objects weather field
 *
 *  When called this function returns the generated weather type for this
 *  biome.
 */
inline Weather Biome::getWeatherType () { return weather; }

/**
 *  getLandscapeType
 *
 *  @returns Landscape    The value of the objects landscape field
 *
 *  When called this function returns the generated landscape type for this
 *  biome.
 */
inline Landscape Biome::getLandscapeType () { return landscape; }

/**
 *  getMainResourceType
 *
 *  @returns Resources    The value of the objects main/abundant resource field
 *
 *  When called this function returns the generated main resource type for this
 *  biome.
 */
inline Resources Biome::getMainResourcesType () { return mainResource; }

/**
 *  getAuxResourceType
 *
 *  @returns Resources    The value of the objects secondary/sparse resource field
 *
 *  When called this function returns the generated aux resource type for this
 *  biome.
 */
inline Resources Biome::getAuxResourcesType () { return auxResource; }


inline Vegitation Biome::getVegitationType () { return vegitation; }

/** 
 *  toString
 *
 *  @returns std::string     A string representing the values of this biome
 *
 *  When called this function will return a string object containing a human
 *  readable translation of the biomes generated configuration.
 */
std::string Biome::toString() {
    std::string output = "";
    
    output += "\tWeather:             ";
    if      (weather == Snow)            output += "\tSnow\n";
    else if (weather == Desert)          output += "\tDesert\n";
    else if (weather == Normal)          output += "\tNormal\n";
    else if (weather == Volcanic)        output += "\tVolcanic\n";
    
    output += "\tLandscape:           ";
    if      (landscape == Mountainous)   output += "\tMountainous\n";
    else if (landscape == Flatlands)     output += "\tFlatlands\n";
    else if (landscape == Hilly)         output += "\tHilly\n";
    
    output += "\tVegitation:          ";
    if      (vegitation == Plentiful)    output += "\tPlentiful\n";
    else if (vegitation == Moderate)     output += "\tModerate\n";
    else if (vegitation == Sparse)       output += "\tSparse\n";
    
    output += "\tMain Resources:      ";
    if      (mainResource == Bronze)     output += "\tBronze\n";
    else if (mainResource == Iron)       output += "\tIron\n";
    else if (mainResource == Steel)      output += "\tSteel\n";
    else if (mainResource == Alluminium) output += "\tAlluminium\n";
    else if (mainResource == Diamond)    output += "\tDiamond\n";
    
    output += "\tAuxiliary Resources: ";
    if      (auxResource == Bronze)      output += "\tBronze\n";
    else if (auxResource == Iron)        output += "\tIron\n";
    else if (auxResource == Steel)       output += "\tSteel\n";
    else if (auxResource == Alluminium)  output += "\tAlluminium\n";
    else if (auxResource == Diamond)     output += "\tDiamond\n";
    
    output += "\n";
    return output;
}
