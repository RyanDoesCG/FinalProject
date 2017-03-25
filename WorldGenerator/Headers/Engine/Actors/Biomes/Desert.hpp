//
//  Desert.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Desert_hpp
#define Desert_hpp

#include "Biome.hpp"

class Desert : public Biome {
    public:
        Desert () {}
       ~Desert () {}

        vec4 getPrimaryColour    () override { return Desert::primaryColour; }; // above water
        vec4 getSecondaryColour  () override { return Desert::secondaryColour; }; // above water
        vec4 getThirdaryColour   () override { return Desert::thirdaryColour; };
        vec4 getUnderwaterColour () override { return Desert::underwaterColour; }; // under water
        vec4 getMountainColour   () override { return Desert::mountainColour; };

        std::string getTreePath () override { return tree; }
        std::string getRockPath () override { return rock; }

    private:
        const vec4 primaryColour    = vec4(0.874, 0.815, 0.705, 1.0);
        const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0);
        const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);
        const vec4 underwaterColour = vec4(0.670, 0.686, 0.631, 0.25);
        const vec4 mountainColour   = getSecondaryColour();
    
        const std::string tree = "Desert/tree";
        const std::string rock = "Desert/rock";
};

#endif /* Desert_hpp */
