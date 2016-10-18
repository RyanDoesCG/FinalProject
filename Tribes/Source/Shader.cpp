/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Shader.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Shader.hpp"
#include "../Headers/GLFW/glfw3.h"

#include <fstream>
#include <math.h>

Shader::Shader(const std::string& name) {
    // create shader program
    programID = glCreateProgram();
    
    // create a fragment and vertex shader
    vertexShaderID   = createShader(loadSource("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = createShader(loadSource("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // attach shaders
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, fragmentShaderID);
    
    // link
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

Shader::~Shader() {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void Shader::bind() {
    glUseProgram(programID);
}

std::string Shader::loadSource(const std::string& path) {
    std::ifstream source;
    
    source.open(path.c_str());
    
    std::string output;
    std::string line;
    
    if (source.is_open()) {
        while(source.good()) {
            getline(source, line);
            output.append(line + "\n");
        }
    }
    
    else {
        std::cout << "Shader Loading Error" << "\n";
    }
    
    return output;
}

GLuint Shader::createShader (const std::string& source, GLenum type) {
    GLuint shader = glCreateShader(type);
    
    if (!shader) std::cout << "Shader Creation Error" << std::endl;
    
    const GLchar* shaderSource[1];
    GLint         sourceLength[1];
    
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
        std::cout << "Shader Compilation Error: " << info << std::endl;
    }
    
    else {
        std::cout << " Shader Compilation Success" << std::endl;
    }
    
    return shader;
}
