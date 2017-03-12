//
//  Shader.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Shader.hpp"
#include <fstream>

GLuint programID;
GLuint vertexShaderID;
GLuint geometryShaderID;
GLuint fragmentShaderID;

Shader::Shader(const std::string& name) {
    /* * * * * * * *
     *  Shader
     * * * * * * * */
    programID = glCreateProgram();
    title = name;
    
    // create a fragment and vertex shader
    vertexShaderID   = compile (load ("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = compile (load ("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
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

Shader::~Shader () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void Shader::bind   () { glUseProgram(programID); }
void Shader::unbind () { glUseProgram(0); }

GLuint Shader::getProgramID() { return programID; }
std::string Shader::getTitle() { return title; }

std::string Shader::load (const std::string& path) {
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

GLuint Shader::compile (const std::string& source, GLenum type) {
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
