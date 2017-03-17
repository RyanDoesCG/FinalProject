//
//  BasicShader.cpp
//  WorldGenerator
//
//  Created by user on 16/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "BasicShader.hpp"

BasicShader::BasicShader (std::string name) {
    programID = glCreateProgram();
    title = name;
    
    // Compile
    vertexShaderID   = compile (load ("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    fragmentShaderID = compile (load ("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // Link
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, fragmentShaderID);
    glLinkProgram  (programID);
    
    checkErrors();
    bind();
    
    // delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

BasicShader::~BasicShader () {
    glDetachShader  (programID, vertexShaderID);
    glDetachShader  (programID, fragmentShaderID);
}
