//
//  GeometryShader.cpp
//  WorldGenerator
//
//  Created by user on 16/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "GeometryShader.hpp"

GeometryShader::GeometryShader (std::string name) {
    programID = glCreateProgram();
    title = name;
    
    // Compile
    vertexShaderID   = compile (load ("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    geometryShaderID = compile (load ("Assets/shaders/" + name + ".geom"), GL_GEOMETRY_SHADER);
    fragmentShaderID = compile (load ("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // Link
    glAttachShader (programID, vertexShaderID);
    glAttachShader (programID, geometryShaderID);
    glAttachShader (programID, fragmentShaderID);
    glLinkProgram  (programID);
    
    checkErrors();
    bind();
    
    // delete shaders
    glDeleteShader (vertexShaderID);
    glDeleteShader (fragmentShaderID);
    glDeleteShader (fragmentShaderID);
}

GeometryShader::~GeometryShader () {
    glDetachShader (programID, vertexShaderID);
    glDetachShader (programID, geometryShaderID);
    glDetachShader (programID, fragmentShaderID);
}
