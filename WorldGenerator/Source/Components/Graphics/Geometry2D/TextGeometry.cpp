//
//  TextGeometry.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "TextGeometry.hpp"
#include <iostream>

TextGeometry::TextGeometry () {
    vertices = {};
    indices  = {};

    Geometry::setup();
}

TextGeometry::~TextGeometry () {}

void TextGeometry::print (TextDrawCall text) { calls.push_back(text); }

void TextGeometry::setup () {
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

void TextGeometry::render () {
    for (TextDrawCall call : calls) {
        
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);
        
       // glUniform4fv(glGetUniformLocation(material.getProgramID(), "colour"), 1, glm::value_ptr(call.col));
        
        // Iterate through all characters
        std::string::const_iterator c;
        /*
        for (c = call.text.begin(); c != call.text.end(); c++) {
            Character ch   = charmap[*c];
            GLfloat   xpos = call.pos.x + ch.Bearing.x * (call.scale);
            GLfloat   ypos = call.pos.y - (ch.Size.y - ch.Bearing.y) * call.scale;
            GLfloat   w    = ch.Size.x * (call.scale);
            GLfloat   h    = ch.Size.y * call.scale;
            
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
            call.pos.x += (ch.Advance >> 6) * call.scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
        }
        
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
         */
    }
}
