//
//  Alien.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Alien_hpp
#define Alien_hpp

#include "Random.hpp"
#include "Biome.hpp"

class Alien : public Biome {
public:
    Alien () {}
    ~Alien () {}
    
    vec4 getPrimaryColour    () override { return vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 1.0); }; // above water
    vec4 getSecondaryColour  () override { return vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 1.0); }; // above water
    vec4 getThirdaryColour   () override { return vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 1.0); };
    vec4 getUnderwaterColour () override { return vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 0.25); }; // under water
    vec4 getMountainColour   () override { return vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 1.0); };
    
    std::string getTreePath () override { return tree; }
    std::string getRockPath () override { return rock; }
    
private:

    const std::string tree = "Desert/tree";
    const std::string rock = "Desert/rock";
};

#endif /* Alien_hpp */
