//
//  Forrest.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Forrest_hpp
#define Forrest_hpp

#include "Biome.hpp"

class Forrest : public Biome {
public:
    Forrest () {}
    ~Forrest () {}
    
    vec4 getPrimaryColour    () override { return Forrest::primaryColour; }; // above water
    vec4 getSecondaryColour  () override { return Forrest::secondaryColour; }; // above water
    vec4 getThirdaryColour   () override { return Forrest::thirdaryColour; };
    vec4 getUnderwaterColour () override { return Forrest::underwaterColour; }; // under water
    vec4 getMountainColour   () override { return Forrest::mountainColour; };
    
    std::string getTreePath () override { return tree; }
    std::string getRockPath () override { return rock; }
    
private:
    const vec4 primaryColour    = vec4(0.874, 0.815, 0.705, 1.0);  // WRONG
    const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0);  // WRONG
    const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);  // WRONG
    const vec4 underwaterColour = vec4(0.670, 0.686, 0.631, 0.25); // WRONG
    const vec4 mountainColour   = getSecondaryColour();
    
    const std::string tree = "Forrest/tree";
    const std::string rock = "Forrest/rock";
};

#endif /* Forrest_hpp */
