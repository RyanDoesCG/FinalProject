//
//  ComplexMaterial.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ComplexMaterial.hpp"
#include <fstream>

ComplexMaterial::ComplexMaterial (const std::string& name) {
    programID = glCreateProgram();
    title = name;
    
    // create a fragment and vertex shader
    vertexShaderID   = create (load ("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    geometryShaderID = create (load ("Assets/shaders/" + name + ".geom"), GL_GEOMETRY_SHADER);
    fragmentShaderID = create (load ("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // attach said shaders
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, geometryShaderID);
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
    glDeleteShader(geometryShaderID);
    glDeleteShader(fragmentShaderID);
    
}

GLuint ComplexMaterial::getProgramID() {
    return programID;
}

std::string ComplexMaterial::getTitle() {
    return title;
}

ComplexMaterial::~ComplexMaterial () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, geometryShaderID);
    glDetachShader  (programID, fragmentShaderID);
    glDeleteProgram (programID);
}

void ComplexMaterial::bind() {
    glUseProgram(programID);
}

std::string ComplexMaterial::load (const std::string& path) {
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

GLuint ComplexMaterial::create (const std::string& source, GLenum type) {
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
