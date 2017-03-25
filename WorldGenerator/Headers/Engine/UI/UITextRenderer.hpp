//
//  UITextRenderer.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UITextRenderer_hpp
#define UITextRenderer_hpp

#include "glew.h"
#include "glm.hpp"
#include <string>
#include <queue>

#include "TextObject.hpp"
#include "TextDrawCall.hpp"
#include <include/ft2build.h>
#include FT_FREETYPE_H

// SINGLETON

class UITextRenderer {
    public:
        static void initialise ();
    
        static void write (std::string text, glm::vec2 pos, glm::vec3 col, float scale);
    
    private:
        static TextObject object;

        static std::queue<DrawCall> drawQueue;
        static FT_Library ft;
        static FT_Face face;
};

#endif /* UITextRenderer_hpp */
