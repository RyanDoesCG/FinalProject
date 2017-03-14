//
//  Texture.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Texture.hpp"
#include "SOIL.h"

Texture::Texture(std::string name) {
    /* * * * * * * *
     *  Texture
     * * * * * * * */
    int width;
    int height;
    std::string path = "Assets/textures/" + name;
    unsigned char* image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture (GLuint id) {
    textureID = id;
}

Texture::Texture() {
    // do nothing
}

Texture::~Texture () {
    
}

void Texture::bind () {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind () {
    glBindTexture(GL_TEXTURE_2D, 0);
}
