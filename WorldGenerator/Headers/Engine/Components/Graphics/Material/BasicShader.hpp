//
//  BasicShader.hpp
//  WorldGenerator
//
//  Created by user on 16/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef BasicShader_hpp
#define BasicShader_hpp

#include "Shader.hpp"

/** 
 * A shader with a vertex -> fragment pipeline
 */
class BasicShader: public Shader {
    public:
        BasicShader (std::string name);
       ~BasicShader ();
    
    private:
        GLuint vertexShaderID;
        GLuint fragmentShaderID;
    
};

#endif /* BasicShader_hpp */
