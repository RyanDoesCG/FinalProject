//
//  ColourPalette.cpp
//  Tribes
//
//  Created by user on 08/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/ColourPalette.hpp"

typedef std::pair<std::string, glm::vec3> Colour;

ColourPalette::ColourPalette () {
    palette = std::map<std::string, glm::vec3>();
    
    palette.insert(Colour("black", glm::vec3(0.0, 0.0, 0.0)));
    palette.insert(Colour("white", glm::vec3(1.0, 1.0, 1.0)));
    palette.insert(Colour("gray", glm::vec3(0.5, 0.5, 0.5)));
}

ColourPalette::~ColourPalette () {
    
}

glm::vec3 ColourPalette::getColour (std::string name) {
    return palette.at(name);
}
