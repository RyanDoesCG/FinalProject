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

    Geometry::setup();
}

TextGeometry::~TextGeometry () {}

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
    
}
