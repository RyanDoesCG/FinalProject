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

Material:: Material (const std::string& shaderName, std::string textureName): shader(shaderName), texture(textureName) {}
Material:: Material (const std::string& shaderName, GLuint textureID):        shader(shaderName), texture(textureID) {}
Material:: Material (const std::string& name):                                shader(name) {}
Material::~Material () {}

GLuint      Material::getProgramID () { return shader.getProgramID(); }
std::string Material::getTitle     () { return shader.getTitle(); }

void Material::bind() {
    shader.bind();
    texture.bind();
}

void Material::unbind() {
    shader.unbind();
    texture.unbind();
}


