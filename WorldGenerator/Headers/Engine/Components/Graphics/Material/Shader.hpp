//
//  Shader.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <iostream>
#include "glew.h"

class Shader {
    public:
        Shader (const std::string& name);
       ~Shader ();
    
       void bind   ();
       void unbind ();
    
       GLuint getProgramID  ();
       std::string getTitle ();
    
    private:
        std::string load (const std::string& path);
        GLuint compile   (const std::string& source, GLenum type);
    
        std::string title;
    
        GLuint programID;
        GLuint vertexShaderID;
        GLuint fragmentShaderID;
};

#endif /* Shader_hpp */
