/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Shader.hpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Shader_hpp
#define Shader_hpp

#include "../GLEW/glew.h"
#include <iostream>

/** 
 *  Shader Class
 *
 */
class Shader {
    public:
        Shader  (const std::string& name);
        ~Shader ();

        void bind();
    
        GLuint getProgramID () { return programID; }
        std::string getProgramTitle () { return title; }

    private:
        std::string loadSource   (const std::string& path);
        GLuint      createShader (const std::string& source, GLenum type);

        GLuint programID;
        GLuint vertexShaderID;
        GLuint fragmentShaderID;
    
        std::string title;
};

#endif /* Shader_hpp */
