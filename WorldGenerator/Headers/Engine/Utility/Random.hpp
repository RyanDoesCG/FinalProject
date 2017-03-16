//
//  Random.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Random_hpp
#define Random_hpp

#include <iostream>

static float unsignedRand () {
    // make a float between 0.0 and 1.0
    return (float)(rand() % 100) / 100;
}

static float betterRand () {
    // make a float between 0.0 and 1.0
    float value = (float)(rand() % 100) / 100;
    
    // negate it half the time
    float ting = (rand() % 100);
    if (ting >= 50) { value *= -1; }
    
    // hand it back
    return value;
}


#endif /* Random_hpp */
