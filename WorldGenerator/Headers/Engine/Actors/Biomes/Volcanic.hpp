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
    
    std::string getTreePath () override { return tree; }
    std::string getRockPath () override { return rock; }
    
private:
    const vec4 primaryColour    = vec4(0.874, 0.815, 0.705, 1.0);   // WRONG
    const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0);   // WRONG
    const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);   // WRONG
    const vec4 underwaterColour = vec4(0.670, 0.686, 0.631, 0.25);  // WRONG
    const vec4 mountainColour   = getSecondaryColour();
    
    const std::string tree = "Volcanic/tree";
    const std::string rock = "Volcanic/rock";
};

#endif /* Volcanic_hpp */
