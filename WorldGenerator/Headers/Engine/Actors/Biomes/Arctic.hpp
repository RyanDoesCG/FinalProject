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
    
    std::string getTreePath () override { return tree; }
    std::string getRockPath () override { return rock; }
    
private:
    const vec4 primaryColour    = vec4(0.874, 0.815, 0.705, 1.0);
    const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0);
    const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);
    const vec4 underwaterColour = vec4(0.670, 0.686, 0.631, 0.25);
    const vec4 mountainColour   = getSecondaryColour();
    
    const std::string tree = "Arctic/tree";
    const std::string rock = "Arctic/rock";
};

#endif /* Arctic_hpp */
