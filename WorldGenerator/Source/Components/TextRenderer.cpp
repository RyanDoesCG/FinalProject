//
//  TextRenderer.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 01/04/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "matrix_transform.hpp"
#include "type_ptr.hpp"
#include "TextRenderer.hpp"
#include "ShaderCache.hpp"

TextRenderer::TextRenderer (float width, float height) {
    this->width = width;
    this->height = height;
    
    // SETUP FREETYPE
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR: freetype failed to initialize" << std::endl;
    
    if (FT_New_Face(ft, "Assets/fonts/AndaleMono.ttf", 0, &face))
        std::cout << "ERROR: failed to load font" << std::endl;
    
    FT_Set_Pixel_Sizes(face, 0, 120);
    
    // SETUP SHADER
    shader = ShaderCache::loadBasicShader("text");
    projection = glm::ortho(0.0f, width, 0.0f, height);
    glUniformMatrix4fv (glGetUniformLocation(shader->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    // SETUP CHARMAP
    charmap = std::map<GLchar, Character>();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    for (GLubyte c = 0; c < 128; c++) {
        // load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            std::cout << "ERROR: failed to laod glyph" << std::endl;
        
        // generate a texture
        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer);
        
        // texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        // store character
        Character ch = {
            textureID,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left,  face->glyph->bitmap_top),
            static_cast<GLuint>(face->glyph->advance.x)
        };
        
        charmap.insert(std::pair<GLchar, Character>(c, ch));
    }
    
    // TIDY UP FREETYPE
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
    // VERTEX DATA
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    
    glBindVertexArray (VAO);
    
        glBindBuffer (GL_ARRAY_BUFFER, VBO);
        glBufferData (GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray (0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray (0);
    
}

void TextRenderer::addToQueue (std::string txt, glm::vec2 pos, float scl, glm::vec3 col) {
    DrawCall call;
    
    call.txt = txt;
    call.pos = glm::vec2((width / 2) + (pos.x - (txt.length() * (scl * 32))), (height / 2) + pos.y);
    call.col = col;
    call.scl = scl;
    
    renderQueue.push(call);
}

void TextRenderer::render() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   // glDisable(GL_DEPTH_TEST);
    shader->bind();
    
    while (!renderQueue.empty()) {
        DrawCall call = renderQueue.front();
        
        // pass shit to shader
        glUniform3f(glGetUniformLocation(shader->getProgramID(), "col"), call.col.r, call.col.g, call.col.b);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);
        
        //
        std::string::const_iterator c;
        
        for (c = call.txt.begin(); c != call.txt.end(); c++) {
            Character ch = charmap[*c];
            GLfloat   x = call.pos.x + ch.bearing.x * (call.scl);
            GLfloat   y = call.pos.y - (ch.size.y - ch.bearing.y) * call.scl;
            GLfloat   w = ch.size.x * call.scl;
            GLfloat   h = ch.size.y * call.scl;
            
            // update VBO
            GLfloat vertices [6][4] = {
                { x,     y + h, 0.0, 0.0},
                { x,     y,     0.0, 1.0},
                { x + w, y,     1.0, 1.0},
                
                { x,     y + h, 0.0, 0.0},
                { x + w, y,     1.0, 1.0},
                { x + w, y + h, 1.0, 0.0}
            };
            
            // ren dar
            glBindTexture(GL_TEXTURE_2D, ch.textureID);
            
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindBuffer (GL_ARRAY_BUFFER, 0);
            
            glDrawArrays(GL_TRIANGLES, 0, 6);
            call.pos.x += (ch.advance >> 6) * call.scl;
        }
        
        glBindVertexArray (0);
        glBindTexture(GL_TEXTURE_2D, 0);
        
        renderQueue.pop();
    }
    
    //glEnable(GL_DEPTH_TEST);
}

TextRenderer::~TextRenderer () {}
