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

GLuint programID;
GLuint vertexShaderID;
GLuint geometryShaderID;
GLuint fragmentShaderID;

GLuint textureID;

Material::Material(const std::string& shaderName, std::string textureName) {
    /* * * * * * * *
     *  Shader
     * * * * * * * */
    programID = glCreateProgram();
    title = shaderName;
    
    // create a fragment and vertex shader
    vertexShaderID   = create (load ("Assets/shaders/" + shaderName + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = create (load ("Assets/shaders/" + shaderName + ".frag"), GL_FRAGMENT_SHADER);
    
    // attach said shaders
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, fragmentShaderID);
    
    // link program
    glLinkProgram  (programID);
    
    // ERROR CHECKING
    GLint  success;
    GLchar info[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, info);
        std::cout << "Shader Program Link Error: " << info << std::endl;
    }
    
    bind();
    
    // delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    
    /* * * * * * * *
     *  Texture
     * * * * * * * */
    int width;
    int height;
    unsigned char* image = SOIL_load_image("Assets/textures/rock.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    
    glGenTextures(1, &textureID);
    
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

Material::Material (const std::string& name) {
    programID = glCreateProgram();
    title = name;
    
    // create a fragment and vertex shader
    vertexShaderID   = create (load ("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = create (load ("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // attach said shaders
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, fragmentShaderID);
    
    // link program
    glLinkProgram  (programID);
    
    // ERROR CHECKING
    GLint  success;
    GLchar info[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, info);
        std::cout << "Shader Program Link Error: " << info << std::endl;
    }
    
    bind();
    
    // delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

}

GLuint Material::getProgramID() {
    return programID;
}

std::string Material::getTitle() {
    return title;
}

Material::~Material () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void Material::bind() {
    glUseProgram(programID);
    glBindTexture(GL_TEXTURE_2D, textureID);
}

std::string Material::load (const std::string& path) {
    std::ifstream source;
    std::string   output;
    std::string   line;
    
    source.open(path.c_str());
    
    if (source.is_open()) {
        while (source.good()) {
            getline(source, line);
            output.append(line + "\n");
        }
    }
    
    else {
        std::cout << "Error loading " << path << std::endl;
    }
    
    return output;
}

GLuint Material::create (const std::string& source, GLenum type) {
    GLuint shader = glCreateShader(type);
    
    if (!shader) std::cout << "Shader Creation Error" << std::endl;
    
    const GLchar* shaderSource[1];
    GLint sourceLength[1];
    
    shaderSource[0] = source.c_str();
    sourceLength[0] = (int)source.length();
    
    glShaderSource  (shader, 1, shaderSource, sourceLength);
    glCompileShader (shader);
    
    // ERROR CHECKING
    GLint  success;
    GLchar info[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info);
        std::cout << title << " ";
        if      (type == GL_VERTEX_SHADER)   std::cout << "Vertex";
        else if (type == GL_FRAGMENT_SHADER) std::cout << "Fragment";
        std::cout << " Shader Compilation Error: " << info << std::endl;
    }
    
    return shader;
}
