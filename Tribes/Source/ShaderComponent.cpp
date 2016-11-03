/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/ShaderComponent.hpp"
#include <fstream>

ShaderComponent::ShaderComponent (const std::string& name) {
    programID = glCreateProgram();
    title = name;
    
    // create a fragment and vertex shader
    vertexShaderID   = createShader(loadSource("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = createShader(loadSource("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
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
    
    update(); // is this necessary???????
    
    // delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

ShaderComponent::~ShaderComponent () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void ShaderComponent::init () {
    
}

void ShaderComponent::update() {
    glUseProgram(programID);
}

std::string ShaderComponent::loadSource (const std::string& path) {
    std::ifstream source;
    
    source.open(path.c_str());
    
    std::string output, line;
    
    if (!source.is_open()) {
        std::cout << "SHADER LOAD ERROR at " << path << std::endl;
    }
    
    else {
        while (source.good()) {
            getline(source, line);
            output.append(line + "\n");
        }
    }
    
    return output;
}

GLuint ShaderComponent::createShader (const std::string& source, GLenum type) {
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
    
    else {
        std::cout << title << " ";
        if      (type == GL_VERTEX_SHADER)   std::cout << "Vertex";
        else if (type == GL_FRAGMENT_SHADER) std::cout << "Fragment";
        std::cout << " Shader Compilation Success" << std::endl;
    }
    
    return shader;
}
