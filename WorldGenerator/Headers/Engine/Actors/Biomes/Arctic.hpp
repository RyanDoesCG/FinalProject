//
//  Arctic.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Arctic_hpp
#define Arctic_hpp

#include "Biome.hpp"

class Arctic : public Biome {
public:
    Arctic () {}
    ~Arctic () {}
    
    vec4 getPrimaryColour    () override { return Arctic::primaryColour; }; // above water
    vec4 getSecondaryColour  () override { return Arctic::secondaryColour; }; // above water
    vec4 getThirdaryColour   () override { return Arctic::thirdaryColour; };
    vec4 getUnderwaterColour () override { return Arctic::underwaterColour; }; // under water
    vec4 getMountainColour   () override { return Arctic::mountainColour; };
    
    glm::vec4 getTreeColour () override { return treeColour; }
    std::string getTreePath () override { return tree; }
    int getMaxTreeCount     () override { return maxTreeCount; }
    int getMinTreeCount     () override { return minTreeCount; }
    
    glm::vec4 getRockColour () override { return treeColour; }
    std::string getRockPath () override { return tree; }
    int getMaxRockCount     () override { return maxTreeCount; }
    int getMinRockCount     () override { return minTreeCount; }
    
private:
    const vec4 primaryColour    = vec4(1.0, 1.0, 1.0, 1.0); // WRONG
    const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0); // WRONG
    const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0); // wRONG
    const vec4 underwaterColour = vec4(0.694, 0.866, 0.945, 0.25);
    const vec4 mountainColour   = getSecondaryColour();

    const vec4 treeColour  = glm::vec4(0.9, 1.0, 0.9, 1.0);
    const std::string tree = "Arctic/tree";
    const int maxTreeCount = 0;
    const int minTreeCount = 0;
    
    const vec4 rockColour  = glm::vec4(0.8, 0.8, 0.8, 1.0);
    const std::string rock = "Arctic/rock";
    const int maxRockCount = 0;
    const int minRockCount = 0;
};

#endif /* Arctic_hpp */
