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

#include "glew/glew.h"
#include <iostream>

#define NUM_SHADERS  2

class Shader {
    public:
    
        Shader  (const std::string& name);
        ~Shader ();

        void bind();
        void update();
        GLuint programID;
        GLuint shaders[NUM_SHADERS];

    private:
        std::string loadSource (const std::string& path);
        GLuint      createShader (const std::string& source, GLenum type);

    
};

#endif /* Shader_hpp */
