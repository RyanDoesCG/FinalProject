//
//  RegShader.cpp
//  WorldGenerator
//
//  Created by user on 25/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include <stdio.h>

#include "../../Headers/Engine/Utility/RegShader.hpp"
#include <fstream>

RegShader::RegShader (const std::string& name) {
    programID   = glCreateProgram();
    title       = name;
    
    // create a fragment and vertex shader
    vertexShaderID   = createShader(loadSource(name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = createShader(loadSource(name + ".frag"), GL_FRAGMENT_SHADER);
    
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
    
    bind(); // is this necessary???????
    
    // delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

RegShader::~RegShader () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void RegShader::bind() {
    glUseProgram(programID);
}

void RegShader::unbind() {
    glUseProgram(0);
}

void RegShader::AddAttribute(std::string name) {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
}

void RegShader::AddUniform(std::string name) {
    
}

void RegShader::passUniform1i(std::string name, int value) {
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void RegShader::passUniform2i(std::string name, int value1, int value2) {
    glUniform2i(glGetUniformLocation(programID, name.c_str()), value1, value2);
}

void RegShader::passUniform1f(std::string name, float value) {
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void RegShader::passVector3(std::string name, GLsizei count, const GLfloat * vec) {
    glUniform3fv(glGetUniformLocation(programID, name.c_str()), 1, vec);
}

void RegShader::passMatrix4(std::string name, GLsizei count, GLboolean transpose, const GLfloat * mat) {
    glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), count, transpose, mat);
}

std::string RegShader::loadSource (const std::string& path) {
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

GLuint RegShader::createShader (const std::string& source, GLenum type) {
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
    
    else if (success) {
        std::cout << title << " ";
        if      (type == GL_VERTEX_SHADER)   std::cout << "Vertex";
        else if (type == GL_FRAGMENT_SHADER) std::cout << "Fragment";
        std::cout << " Shader Compilation Success" << std::endl;
    }
    
    return shader;
}

GLuint RegShader::getProgramID() {
    return programID;
}
