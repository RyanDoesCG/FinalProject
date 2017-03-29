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

        glm::vec4 getTreeColour () override { return treeColour; }
        std::string getTreePath () override { return tree; }
        int getMaxTreeCount     () override { return maxTreeCount; }
        int getMinTreeCount     () override { return minTreeCount; }
    
        glm::vec4 getRockColour () override { return treeColour; }
        std::string getRockPath () override { return rock; }
        int getMaxRockCount     () override { return maxTreeCount; }
        int getMinRockCount     () override { return minTreeCount; }

    private:
        const vec4 primaryColour    = vec4(0.874, 0.815, 0.705, 1.0);
        const vec4 secondaryColour  = vec4(0.937, 0.776, 0.576, 1.0);
        const vec4 thirdaryColour   = vec4(0.827, 0.576, 0.274, 1.0);
        const vec4 underwaterColour = vec4(0.670, 0.686, 0.631, 0.25);
        const vec4 mountainColour   = getSecondaryColour();
    
        const vec4 treeColour  = glm::vec4(0);
        const std::string tree = "Desert/tree";
        const int maxTreeCount = 0;
        const int minTreeCount = 0;
    
        const vec4 rockColour  = glm::vec4(0);
        const std::string rock = "Desert/rock";
        const int maxRockCount = 0;
        const int minRockCount = 0;
};

#endif /* Desert_hpp */
