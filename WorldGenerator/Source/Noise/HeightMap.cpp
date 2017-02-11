//
//  HeightMap.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Noise/HeightMap.hpp"
#include "../../Headers/Engine/Utility/BetterRand.hpp"
#include <iostream>

HeightMap::HeightMap (int w, int h): width(w), height(h) {
    generate();
    
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, textureData);
    
}

HeightMap::~HeightMap () {
    
}

/** 
 *  populate data array
 */
void HeightMap::generate() {
    textureData = new GLfloat[width * height * 3];
    
    // write some random data
    for (int x = 0; x < width * height * 3; x++) {
        textureData[x] = unsignedRand();
    }
}

/** 
 *
 */
void HeightMap::bind () {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

/** 
 *  save texture to disk as jpg
 */
void HeightMap::writeToDisk() {
    
}
