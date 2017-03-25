//
//  UITextRenderer.cpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "UITextRenderer.hpp"
#include <iostream>

void UITextRenderer::initialise() {
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR: Could not init FreeType Library" << std::endl;
    
    if (FT_New_Face(ft, "Assets/fonts/AppleGothic.ttf", 0, &face))
        std::cout << "ERROR: Failed to load font" << std::endl;
    
    FT_Set_Pixel_Sizes(face, 0, 120);
}

void UITextRenderer::write(std::string text, glm::vec2 pos, glm::vec3 col, float scale) {
    DrawCall call;
    
    call.text = text;
    call.pos = pos;
    call.col = col;
    call.scale = scale;
    
    drawQueue.push(call);
}
