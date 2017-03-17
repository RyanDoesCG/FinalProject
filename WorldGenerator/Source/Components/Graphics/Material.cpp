//
//  Material.cpp
//  WorldGenerator
//
//  Created by user on 07/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Material.hpp"
#include "SOIL.h"
#include <fstream>

Material:: Material (Shader* s, std::string textureName): shader(s), texture(textureName) {}
Material:: Material (Shader* s, GLuint textureID):        shader(s), texture(textureID) {}
Material:: Material (Shader* s):                          shader(s) {}
Material::~Material () {}

GLuint      Material::getProgramID () { return shader->getProgramID(); }
std::string Material::getTitle     () { return shader->getTitle(); }
void        Material::setTexture(GLuint id) { texture = Texture(id); }

void Material::bind() {
    shader->bind();
    texture.bind();
}

void Material::unbind() {
    shader->unbind();
    texture.unbind();
}


