/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Shader.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Shader.hpp"

#include <fstream>

Shader::Shader  (const std::string& name) {
    // create shader program
    programID = glCreateProgram();
    
    // create a fragment and vertex shader
    shaders[0] = createShader(loadSource("Assets/shaders/" + name + ".vert"), GL_VERTEX_SHADER);
    shaders[1] = createShader(loadSource("Assets/shaders/" + name + ".frag"), GL_FRAGMENT_SHADER);
    
    // attach all shaders to program
    for (unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(programID, shaders[i]);
    
    // bind attributes
    glBindAttribLocation(programID, 0, "position");
    glBindAttribLocation(programID, 1, "textureCoordinate");
    glBindAttribLocation(programID, 2, "normal");
    
    glLinkProgram (programID);
    glValidateProgram(programID);
    
    // *Error Checking: TO-DO*
    
    uniforms[TRANSFORM_U] = glGetUniformLocation(programID, "transform");
}

Shader::~Shader () {
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(programID, shaders[i]);
        glDeleteShader(shaders[i]);
    }
    
    glDeleteProgram(programID);
}

void Shader::bind() {
    glUseProgram(programID);
}

void Shader::update() {

}

std::string Shader::loadSource (const std::string& path) {
    std::ifstream source;
    
    source.open(path.c_str());
    
        std::string output;
    std::string line;
    
    if (source.is_open()) {
        while(source.good()) {
            getline(source, line);
            output.append(line + "\n");
        }
    } else {
        std::cout << "Shader couldnt be loaded from disk" << "\n";
    }
    
    return output;
    
    
}

GLuint Shader::createShader (const std::string& source, GLenum type) {
    GLuint shader = glCreateShader(type);
    
    if (!shader) std::cout << "Shader Creation Error" << "\n";
    
    const GLchar* shaderSource[1];
    GLint         sourceLength[1];
    
    shaderSource[0] = source.c_str();
    sourceLength[0] = (int)source.length();
    
    glShaderSource  (shader, 1, shaderSource, sourceLength);
    glCompileShader (shader);
    
    return shader;
}
