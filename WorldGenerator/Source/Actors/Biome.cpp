//
//  Biome.cpp
//  WorldGenerator
//
//  Created by user on 01/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/Biome.hpp"
#include "../../Headers/Engine/Utility/ColourPalette.hpp"

Biome::Biome() {
    variation = static_cast<Type>(rand() % max);
    //variation = DESERT;
}

Biome::Biome(Type type) {
    variation = type;
}

Biome::~Biome() {}
    
glm::vec3 Biome::getPrimaryColour() {
    switch (variation) {
        case DESERT:    return ColourPalette::getColour(DesertSand);
        case FOREST:    return ColourPalette::getColour(ForestGreen);
        case VOLCANIC:  return ColourPalette::getColour(Error);
        case TROPICAL:  return ColourPalette::getColour(Error);
        case ARCTIC:    return ColourPalette::getColour(ArcticWhite);
        case max: return ColourPalette::getColour(Error);
    }
}

glm::vec3 Biome::getSecondaryColour() {
    switch (variation) {
        case DESERT:    return ColourPalette::getColour(ForestBrown);
        case FOREST:    return ColourPalette::getColour(ForestGreenTheReturn);
        case VOLCANIC:  return ColourPalette::getColour(Error);
        case TROPICAL:  return ColourPalette::getColour(Error);
        case ARCTIC:    return ColourPalette::getColour(ArcticLightGrey);
        case max: return ColourPalette::getColour(Error);
    }
}

glm::vec3 Biome::getTertiaryColour() {
    switch (variation) {
        case DESERT:    return ColourPalette::getColour(DesertGoldenSand);
        case FOREST:    return ColourPalette::getColour(ForestGreenTheReturn);
        case VOLCANIC:  return ColourPalette::getColour(Error);
        case TROPICAL:  return ColourPalette::getColour(Error);
        case ARCTIC:    return ColourPalette::getColour(ArcticGrey);
        case max: return ColourPalette::getColour(Error);
    }
}
    
glm::vec3 Biome::getMountainColour() {
    switch (variation) {
        case DESERT:    return ColourPalette::getColour(DesertGrayGreen);
        case FOREST:    return ColourPalette::getColour(ForestBrown);
        case VOLCANIC:  return ColourPalette::getColour(Error);
        case TROPICAL:  return ColourPalette::getColour(Error);
        case ARCTIC:    return ColourPalette::getColour(ArcticLightBrown);
        case max: return ColourPalette::getColour(Error);
    }
}

glm::vec3 Biome::getUnderWaterColour() {
    switch (variation) {
        case DESERT:    return ColourPalette::getColour(DesertPaleLime);
        case FOREST:    return ColourPalette::getColour(ForestBrown);
        case VOLCANIC:  return ColourPalette::getColour(Error);
        case TROPICAL:  return ColourPalette::getColour(Error);
        case ARCTIC:    return ColourPalette::getColour(ArcticBabyBlue);
        case max: return ColourPalette::getColour(Error);
    }
}

