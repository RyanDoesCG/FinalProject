/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  NoiseInterface.cpp
 *  Tribes
 *
 *  Created by ryan needham on 23/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Noise/NoiseInterface.hpp"
#include <iostream>

FastNoise NoiseInterface::noiselib = FastNoise(832);

float NoiseInterface::getSimplexNoise (float amplitude, float frequency, float time) {
    //noiselib.SetFrequency(10);
    
    float value = noiselib.GetSimplex(time, 100);
    std::cout << value << std::endl;
    
    return value;
}
