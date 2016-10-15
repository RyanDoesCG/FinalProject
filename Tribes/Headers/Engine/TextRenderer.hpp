/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextRender.hpp
 *  Tribes
 *
 *  Created by user on 14/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TextRender_hpp
#define TextRender_hpp

#include "../Engine/Shader.hpp"

#include "../GLEW/glew.h"
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include <include/ft2build.h>
#include FT_FREETYPE_H

#include <iostream>
#include <map>

struct Character {
    GLuint     textureID;  // ID handle of the glyph texture
    glm::ivec2 Size;       // Size of glyph
    glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
    GLuint     Advance;    // Offset to advance to next glyph
};

class TextRenderer {
    public:
        TextRenderer  ();
    
        ~TextRenderer ();
    
        void renderText(std::string text, int x, int y, int scale);
    
    private:
        std::map<GLchar, Character> charmap;
        glm::mat4 projection;
    
        Shader* shader;
    
        FT_Library ft;
        FT_Face    face;
    
        GLuint VAO;
        GLuint VBO;
};

#endif /* TextRender_hpp */
