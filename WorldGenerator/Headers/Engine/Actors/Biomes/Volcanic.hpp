//
//  Volcanic.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Volcanic_hpp
#define Volcanic_hpp

#include "Biome.hpp"

class Volcanic : public Biome {
public:
    Volcanic () {}
    ~Volcanic () {}
    
    vec4 getPrimaryColour    () override { return Volcanic::primaryColour; }; // above water
    vec4 getSecondaryColour  () override { return Volcanic::secondaryColour; }; // above water
    vec4 getThirdaryColour   () override { return Volcanic::thirdaryColour; };
    vec4 getUnderwaterColour () override { return Volcanic::underwaterColour; }; // under water
    vec4 getMountainColour   () override { return Volcanic::mountainColour; };
    
    glm::vec4 getTreeColour () override { return treeColour; }
    std::string getTreePath () override { return tree; }
    int getMaxTreeCount     () override { return maxTreeCount; }
    int getMinTreeCount     () override { return minTreeCount; }
    
    glm::vec4 getRockColour () override { return treeColour; }
    std::string getRockPath () override { return tree; }
    int getMaxRockCount     () override { return maxTreeCount; }
    int getMinRockCount     () override { return minTreeCount; }
    
private:
    const vec4 primaryColour    = vec4(0.341, 0.345, 0.333, 1.0);
    const vec4 secondaryColour  = vec4(0.611, 0.584, 0.513, 1.0);
    const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);   // WRONG
    const vec4 underwaterColour = vec4(0.513, 0.545, 0.576, 0.65);  // WRONG
    const vec4 mountainColour   = getSecondaryColour();
    
    const vec4 treeColour  = glm::vec4(0.078, 0.078, 0.078, 1.0);
    const std::string tree = "Volcanic/tree";
    const int maxTreeCount = 0;
    const int minTreeCount = 0;
    
    const vec4 rockColour  = secondaryColour;
    const std::string rock = "Volcanic/rock";
    const int maxRockCount = 0;
    const int minRockCount = 0;
};

#endif /* Volcanic_hpp */
