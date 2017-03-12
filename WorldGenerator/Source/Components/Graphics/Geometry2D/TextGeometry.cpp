//
//  TextGeometry.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "TextGeometry.hpp"
#include <iostream>

TextGeometry::TextGeometry (std::string text) {
    vertices = {};
    indices  = {};
    
    // Initialise Freetype
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR: FreeType init error" << std::endl;
    
    // Load a Font
    if (FT_New_Face(ft, "Assets/fonts/AppleGothic.ttf", 0, &face))
        std::cout << "ERROR: Failed to load font" << std::endl;
    
    FT_Set_Pixel_Sizes(face, 0, 120); // fucked?
    
    
    
    
    
    
    Geometry::setup();
}

TextGeometry::~TextGeometry () {}
