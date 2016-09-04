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
    this->weather = static_cast<Weather>(rand() % (WEATHER_MAX + 1));
    this->landscape = static_cast<Landscape>(rand() % (LANDSCAPE_MAX + 1));
    this->vegitation = static_cast<Vegitation>(rand() % (VEGITATION_MAX + 1));
}


Biome::~Biome () {

}

std::string Biome::toString() {
    // TO-DO
    return "unimplemented";
}
