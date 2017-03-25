//
//  Biome.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Biome_hpp
#define Biome_hpp

using namespace glm;

class Biome {
    public:
        virtual vec4 getPrimaryColour    () = 0; // above water
        virtual vec4 getSecondaryColour  () = 0; // above water
        virtual vec4 getThirdaryColour   () = 0;
    
        virtual vec4 getUnderwaterColour () = 0; // under water
        virtual vec4 getMountainColour   () = 0;
    
        virtual std::string getTreePath () = 0;
        virtual std::string getRockPath () = 0;
    
};

#endif /* Biome_hpp */
