/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  NoiseInterface.hpp
 *  Tribes
 *
 *  Created by ryan needham on 23/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef NoiseInterface_hpp
#define NoiseInterface_hpp

#include "../../FastNoise/FastNoise.h"

class NoiseInterface {
    public:
    
        static float getSimplexNoise (float amplitude, float frequency, float time);
    
    private:
        static FastNoise noiselib;
};

#endif /* NoiseInterface_hpp */
