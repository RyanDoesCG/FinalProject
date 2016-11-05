/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextRenderingComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TextRenderingComponent_hpp
#define TextRenderingComponent_hpp

#include "ShaderComponent.hpp"
#include "ActorComponent.hpp"

#include "../GLEW/glew.h"
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include <include/ft2build.h>
#include FT_FREETYPE_H

#include <iostream>
#include <map>

class TextRenderingComponent : public ActorComponent {
public:
     TextRenderingComponent ();
    ~TextRenderingComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
    void renderTextAs2D(std::string text, glm::vec2 position, int scale);
    void renderTextAs3D(std::string text, glm::vec3 position, int scale);
    
private:
    struct Character {
        GLuint     textureID;  // ID handle of the glyph texture
        glm::ivec2 Size;       // Size of glyph
        glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
        GLuint     Advance;    // Offset to advance to next glyph
    };
    
    ShaderComponent textShader;
    std::map<GLchar, Character> charmap;
    glm::mat4 projection;
    
    FT_Library ft;
    FT_Face face;
    
    GLuint VAO;
    GLuint VBO;
};

#endif /* TextRenderingComponent_hpp */
