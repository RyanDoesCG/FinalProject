/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextRenderingComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/TextRenderingComponent.hpp"

TextRenderingComponent::TextRenderingComponent (): textShader(ShaderComponent("Text")) {
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR: Could not init FreeType Library" << std::endl;
    
    if (FT_New_Face(ft, "Assets/fonts/AppleGothic.ttf", 0, &face))
        std::cout << "ERROR: Failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, 24);
    
    projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
    glUniformMatrix4fv(glGetUniformLocation(textShader.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    // construct character map
    charmap = std::map<GLchar, Character>();
    
    // Disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    for (GLubyte c = 0; c < 128; c++) {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) std::cout << "ERROR: Failed to load Glyph" << std::endl;
        
        // Generate texture
        GLuint texture;
        glGenTextures (1, &texture);
        glBindTexture (GL_TEXTURE_2D, texture);
        glTexImage2D (
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        
        // Set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        // Now store character for later use
        Character ch = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            static_cast<GLuint>(face->glyph->advance.x)
        };
        
        this->charmap.insert(std::pair<GLchar, Character>(c, ch));
    }
    
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &VBO);
    
    glBindVertexArray (VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray (0);
    
}

TextRenderingComponent::~TextRenderingComponent () {
    
}

void TextRenderingComponent::init () {
    textShader.init();
}

void TextRenderingComponent::update() {
    textShader.update();
    
    renderTextAs2D("pre-alpha", glm::vec2(10, 10), 1);
}

void TextRenderingComponent::renderTextAs2D(std::string text, glm::vec2 position, int scale) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    textShader.update();
    
    glUniform3f(glGetUniformLocation(textShader.getProgramID(), "textColor"), 0.6, 0.6, 0.6);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);
    
    // Iterate through all characters
    std::string::const_iterator c;
    
    for (c = text.begin(); c != text.end(); c++) {
        Character ch = charmap[*c];
        
        GLfloat xpos = position.x + ch.Bearing.x * (scale);
        GLfloat ypos = position.y - (ch.Size.y - ch.Bearing.y) * scale;
        
        GLfloat w = ch.Size.x * (scale);
        GLfloat h = ch.Size.y * scale;
        
        // Update VBO for each character
        GLfloat vertices[6][4] = {
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos,     ypos,       0.0, 1.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos + w, ypos + h,   1.0, 0.0 }
        };
        // Render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.textureID);
        
        // Update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        // Render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        position.x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextRenderingComponent::renderTextAs3D(std::string text, glm::vec3 position, int scale) {

}
