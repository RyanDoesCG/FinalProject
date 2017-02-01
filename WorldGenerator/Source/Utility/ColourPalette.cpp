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
    Colour(Error,               glm::vec3(1.00f, 0.50f, 0.00f)),
    Colour(ArcticWhite,         glm::vec3(1.00f, 1.00f, 1.00f)),    // arctic
    Colour(ArcticLightGrey,     glm::vec3(0.93f, 0.93f, 0.93f)),    // arctic
    Colour(ArcticGrey,          glm::vec3(0.86f, 0.86f, 0.86f)),    // arctic
    Colour(ArcticBabyBlue,      glm::vec3(0.69f, 0.86f, 0.94f)),    // arctic
    Colour(ArcticLightBrown,    glm::vec3(0.60f, 0.44f, 0.37f)),    // arctic
    Colour(DesertSand,          glm::vec3(0.96f, 0.87f, 0.70f)),    // desert
    Colour(DesertLightSand,     glm::vec3(0.94f, 0.78f, 0.56f)),    // desert
    Colour(DesertGoldenSand,    glm::vec3(0.83f, 0.58f, 0.23f)),    // desert
    Colour(DesertPaleLime,      glm::vec3(0.74f, 0.76f, 0.67f)),    // desert
    Colour(DesertGrayGreen,     glm::vec3(0.67f, 0.68f, 0.62f)),    // desert
    Colour(DesertpaleSand,      glm::vec3(0.87f, 0.81f, 0.70f)),    // desert
    Colour(ForestGreen,                glm::vec3(0.16f, 0.24f, 0.06f)),    // forest
    Colour(ForestGreenTheReturn,       glm::vec3(0.27f, 0.36f, 0.26f)),    // forest
    Colour(ForestBrown,                glm::vec3(0.37f, 0.28f, 0.17f)),
    Colour(ForestSand,                 glm::vec3(0.87f, 0.81f, 0.70f)),
    Colour(ForestGreenTheReReturn,    glm::vec3(0.38f, 0.42f, 0.21f))
};
