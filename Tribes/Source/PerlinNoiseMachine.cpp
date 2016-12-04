/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PerlinNoiseMachine.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/PerlinNoiseMachine.hpp"
#include <iostream>
#include <math.h>   // fmod

float PerlinNoiseMachine::unitRandom() { return float(rand() % 100) / 200; }
float PerlinNoiseMachine::random(int floor, int roof) { return float(fmod(rand(), roof) + floor); }
float PerlinNoiseMachine::noise(double time) { return 0; }

void PerlinNoiseMachine::distortMe(std::vector<Vertex> *vertices) {

}
