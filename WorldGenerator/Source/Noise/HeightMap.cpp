//
//  HeightMap.cpp
//  WorldGenerator
//
//  Created by user on 15/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "SOIL.h"
#include "HeightMap.hpp"
#include <iostream>
HeightMap::HeightMap (std::string name) {
    data = SOIL_load_image(("Assets/textures/" + name).c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    for (int u = 0; u < width; u++) {
        for (int v = 0; v < height; v++) {
            if (data[u + v * width] == 1) {
                std::cout << (int)data[(u + v * width) * 3 + 0] << " ";
                std::cout << (int)data[(u + v * width) * 3 + 1] << " ";
                std::cout << (int)data[(u + v * width) * 3 + 2] << " ";
            }
        }
        std::cout << std::endl;
    }
}

HeightMap::~HeightMap () {
    SOIL_free_image_data(data);
}

GLfloat HeightMap::getHeightAt (GLuint u, GLuint v) {
    return ((u < width) && (v < height)) ?
        data[(u + v * width) * 3 + 0] +
        data[(u + v * width) * 3 + 1] +
        data[(u + v * width) * 3 + 2]
    :
        0.0f;
}
GLuint HeightMap::getID () {
    return textureID;
}
