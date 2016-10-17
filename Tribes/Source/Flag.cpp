/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Flag.cpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Flag.hpp"
#include "../Headers/Engine/FlagGraphics.hpp"
#include <vector>

Flag::Flag () {
    setGraphics(new FlagGraphics());
    generateFlag();
}

Flag::~Flag() {
    std::cout << "Flag Freed" << std::endl;
}

void Flag::generateFlag() {
    
}
