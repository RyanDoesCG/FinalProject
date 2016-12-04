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
    for (int i = 0; i < vertices->size(); i++) {
        Vertex placeholder = Vertex();
        placeholder.position.x = vertices->at(i).position.x + unitRandom();
        placeholder.position.y = vertices->at(i).position.y + unitRandom();
        placeholder.position.z = vertices->at(i).position.z + unitRandom();
        
        vertices->at(i) = placeholder;
    }
}
