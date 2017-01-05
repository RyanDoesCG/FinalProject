/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ColourPalette.cpp
 *  Tribes
 *
 *  Created by user on 08/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Utility/ColourPalette.hpp"

const std::map<ColourID, glm::vec3> ColourPalette::palette = {
    Colour(Black,     glm::vec3(0.0, 0.0, 0.0)),
    Colour(White,     glm::vec3(1.0, 1.0, 1.0)),
    Colour(LightGray, glm::vec3(0.75, 0.75, 0.75)),
    Colour(Gray,      glm::vec3(0.5, 0.5, 0.5)),
    Colour(DarkGray,  glm::vec3(0.15, 0.15, 0.15)),
    Colour(Sand,      glm::vec3(0.77, 0.69, 0.53)),
    Colour(Red,       glm::vec3(0.45, 0.175, 0.175))
};
