//
//  TextRenderer.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 01/04/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef TextRenderer_hpp
#define TextRenderer_hpp

#include <include/ft2build.h>
#include FT_FREETYPE_H

#include "BasicShader.hpp"
#include "glm.hpp"
#include "glew.h"
#include <string>
#include <queue>
#include <map>

// Maintain list of draw calls, called by graphics engine

class TextRenderer {
    public:
        TextRenderer (float width, float height);
       ~TextRenderer ();
    
        void addToQueue (std::string txt,
                         glm::vec2   pos,
                         float       scl,
                         glm::vec3   col);
        void render ();
    
    private:
    
        struct Character {
            GLuint textureID;
            glm::ivec2 size;
            glm::ivec2 bearing;
            GLuint advance;
        };
    
        struct DrawCall {
            std::string txt;
            glm::vec2   pos;
            glm::vec3   col;
            float       scl;
        };
    
        std::queue<DrawCall> renderQueue;
    
        BasicShader* shader;
        std::map<GLchar, Character> charmap;
        glm::mat4 projection;
    
        FT_Library ft;
        FT_Face face;
    
        GLuint VAO;
        GLuint VBO;
    
        float width;
        float height;
    
};

#endif /* TextRenderer_hpp */
