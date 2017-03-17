//
//  UITextNode.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "BasicShader.hpp"
#include "TextGeometry.hpp"
#include "UITextNode.hpp"
#include "Game.hpp"

UITextNode::UITextNode (GraphicsEngine* graph): material(new BasicShader("text")), geometry() {
    /* * * * * * * * * * * * * * * * *
     *  Initialise Library
     * * * * * * * * * * * * * * * * */
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR: Could not init FreeType Library" << std::endl;
    
    if (FT_New_Face(ft, "Assets/fonts/AndaleMono.ttf", 0, &face))
        std::cout << "ERROR: Failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, 48);

    // construct character map
    charmap = std::map<GLchar, Character>();
    
    // Disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (GLubyte c = 0; c < 128; c++) {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) std::cout << "ERROR: " << FT_Load_Char(face, c, FT_LOAD_RENDER) << " Failed to load Glyph" << std::endl;
        
        // Generate texture
        GLuint texture;
        glGenTextures (1, &texture);
        glBindTexture (GL_TEXTURE_2D, texture);
        glTexImage2D  (
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
        
        material.setTexture(texture);
        
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
        
        charmap.insert(std::pair<GLchar, Character>(c, ch));
    }
    
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
    litColour = glm::vec3(0.41, 0.41, 0.41);
    unlitColour = glm::vec3(0.21, 0.21, 0.21);
}

UITextNode::~UITextNode () {
    
}

void UITextNode::update (State state) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable(GL_DEPTH_TEST);
    material.bind();
    
    glm::mat4 projection = glm::ortho(0.0f, 1920.0f * 0.75f, 0.0f, 1080.0f * 0.75f);
    glUniformMatrix4fv(glGetUniformLocation(material.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    for (TextDrawCall& call : drawQueue) {
        geometry.print(call);

    }
    
    glEnable(GL_DEPTH_TEST);
}

void UITextNode::fadeIn() {
    for (TextDrawCall& call : drawQueue) {
        if (call.col.r < litColour.r) {
            call.col.r += 0.01;
            call.col.g += 0.01;
            call.col.b += 0.01;
        }
    }
}

void UITextNode::fadeOut() {
    for (TextDrawCall& call : drawQueue) {
        if (call.col.r > unlitColour.r) {
            call.col.r -= 0.01;
            call.col.g -= 0.01;
            call.col.b -= 0.01;
        }
    }
}
