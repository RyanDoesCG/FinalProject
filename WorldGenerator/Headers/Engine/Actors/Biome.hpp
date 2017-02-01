//
//  Biome.hpp
//  WorldGenerator
//
//  Created by user on 01/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Biome_hpp
#define Biome_hpp

#include "../../glm/glm.hpp"

class Biome {

    public:
        enum Type { DESERT, FOREST, VOLCANIC, TROPICAL, ARCTIC, max};
    
        Biome();
        Biome(Type variation);
       ~Biome();
    
        glm::vec3 getPrimaryColour();
        glm::vec3 getSecondaryColour();
        glm::vec3 getTertiaryColour();
    
        glm::vec3 getMountainColour();
        glm::vec3 getUnderWaterColour();
    
    
    
    private:

        Type variation;
    
};

#endif /* Biome_hpp */
