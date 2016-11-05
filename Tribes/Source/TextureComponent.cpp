/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextureComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/TextureComponent.hpp"
#include "../Headers/SOIL/SOIL.h"

TextureComponent::TextureComponent (std::string path) {
    title = path;
    
    imageData = SOIL_load_image (path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    if (!imageData) std::cout << "IMAGE LOAD FAILURE at Assets/textures/" << path << ".png" << std::endl;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // send to shader, enable mip-mapping and release memory
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        imageData
    );
    
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(imageData);
    
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

}

TextureComponent::~TextureComponent () {
    
}

void TextureComponent::init () {
    glBindTexture (GL_TEXTURE_2D, textureID);
}

void TextureComponent::update() {
    
}

