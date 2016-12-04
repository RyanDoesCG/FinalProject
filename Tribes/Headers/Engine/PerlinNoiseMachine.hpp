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

#include "Vertex.hpp"
#include <vector>

class PerlinNoiseMachine {
public:

    static float unitRandom ();                    // 0 - 1
    static float random (int floor, int roof);     // floor - roof
    static float noise  (double time);             // xoff = time
    
    static void distortMe (std::vector<Vertex>* vertices);

};

#endif /* PerlinNoiseMachine_hpp */
