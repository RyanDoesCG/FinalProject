/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Texture.cpp
 *  Tribes
 *
 *  Created by user on 16/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Texture.hpp"

Texture::Texture(std::string path) {
    path = "Assets/textures/" + path + ".jpg";

    image = SOIL_load_image (
        path.c_str(),
        &width,
        &height,
        0,
        SOIL_LOAD_RGB
    );
    
    if (!image) std::cout << "Image load failure (" << path << ")" << std::endl;
    
    glGenTextures (1, &textureID);
    glBindTexture (GL_TEXTURE_2D, textureID);
        glTexImage2D (
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            width,
            height,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            image
        );
        glGenerateMipmap(GL_TEXTURE_2D);
        SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {

}

void Texture::bind() {
    glBindTexture (GL_TEXTURE_2D, textureID);
}
