/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PerlinNoiseMachine.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PerlinNoiseMachine_hpp
#define PerlinNoiseMachine_hpp

#include <iostream>

class PerlinNoiseMachine {
public:
    PerlinNoiseMachine  ();
    ~PerlinNoiseMachine ();
    
    float random (float floor, float roof);
    float noise  (double time);
    
private:
    
};

#endif /* PerlinNoiseMachine_hpp */
