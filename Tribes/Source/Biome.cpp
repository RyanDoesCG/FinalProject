/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 06/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Biome.hpp"

Biome::Biome  (std::vector<GLfloat>* t) {
    planet = (Planet*)parent;
    territory = *t;
}

Biome::~Biome () {

}

void Biome::init() {
    std::cout << "biome initialised at: [";
    for (int i = 0; i < territory.size(); i++) std::cout << territory.at(i) << ", ";
    std::cout << "];\n";
    
    Actor::init();
}

void Biome::update() {
    Actor::update();
}
