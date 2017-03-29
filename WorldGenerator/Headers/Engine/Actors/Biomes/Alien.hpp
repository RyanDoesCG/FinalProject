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
    
    glm::vec4 getTreeColour () override { return treeColour; }
    std::string getTreePath () override { return tree; }
    int getMaxTreeCount     () override { return maxTreeCount; }
    int getMinTreeCount     () override { return minTreeCount; }
    
    glm::vec4 getRockColour () override { return treeColour; }
    std::string getRockPath () override { return tree; }
    int getMaxRockCount     () override { return maxTreeCount; }
    int getMinRockCount     () override { return minTreeCount; }
    
private:

    const vec4 treeColour  = glm::vec4(0);
    const std::string tree = "Alien/tree";
    const int maxTreeCount = 0;
    const int minTreeCount = 0;
    
    const vec4 rockColour  = glm::vec4(0);
    const std::string rock = "Alien/rock";
    const int maxRockCount = 0;
    const int minRockCount = 0;
};

#endif /* Alien_hpp */
