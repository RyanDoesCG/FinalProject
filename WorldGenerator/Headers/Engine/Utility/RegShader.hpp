//
//  RegShader.hpp
//  WorldGenerator
//
//  Created by user on 25/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef RegShader_hpp
#define RegShader_hpp

#include "../../GLEW/glew.h"
#include "../../GLM/glm.hpp"
#include <iostream>

class RegShader {
public:
    RegShader (const std::string& name);
    ~RegShader ();
    
    void bind   ();
    void unbind ();
    
    GLuint getProgramID();
    
    void AddAttribute(std::string name);
    void AddUniform(std::string name);
    
    void passUniform1i(std::string name, int value);
    void passUniform2i(std::string name, int value1, int value2);
    void passUniform1f(std::string name, float value);
    void passMatrix4  (std::string name, GLsizei count, GLboolean transpose, const GLfloat * mat);
    void passVector3  (std::string name, GLsizei count, const GLfloat * vec);
    
private:
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    
    std::string loadSource   (const std::string& path);
    GLuint      createShader (const std::string& source, GLenum type);
    
    std::string title;
    
};

#endif /* RegShader_hpp */
