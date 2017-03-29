//
//  Biome.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef Biome_hpp
#define Biome_hpp

class Biome {
    public:
        // landscape colour
        virtual glm::vec4 getPrimaryColour    () = 0;
        virtual glm::vec4 getSecondaryColour  () = 0;
        virtual glm::vec4 getThirdaryColour   () = 0;
        virtual glm::vec4 getUnderwaterColour () = 0;
        virtual glm::vec4 getMountainColour   () = 0;
    
        // tree colour and placement data
        virtual glm::vec4 getTreeColour       () = 0;
        virtual std::string getTreePath       () = 0;
        virtual int getMaxTreeCount           () = 0;
        virtual int getMinTreeCount           () = 0;
    
        // rock colour and placement data
        virtual glm::vec4 getRockColour       () = 0;
        virtual std::string getRockPath       () = 0;
        virtual int getMaxRockCount           () = 0;
        virtual int getMinRockCount           () = 0;
    
};

#endif /* Biome_hpp */
