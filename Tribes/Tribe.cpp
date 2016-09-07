/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Tribe.cpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Tribe.hpp"

Tribe::Tribe  () {
        name  = generateName();
        ethos = static_cast<Ethos>(rand() % ETHOS_MAX);
//      flag  = generateFlat();
        population = (rand() % 1000) + 1;
}

Tribe::~Tribe () {

}

std::string Tribe::toString() {
    return std::string();
}

std::string Tribe::generateName() {
    return "name gen not implemented";
}
