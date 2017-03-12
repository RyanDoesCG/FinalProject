//
//  ComplexMaterial.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ComplexMaterial_hpp
#define ComplexMaterial_hpp

#include <iostream>
#include "glm.hpp"
#include "glew.h"

class ComplexMaterial {
    public:
        ComplexMaterial(const std::string& name);
       ~ComplexMaterial();
    
        void bind();
    
        GLuint getProgramID();
        std::string getTitle();
    
    private:
        glm::vec4 colour;
    
        std::string load (const std::string& path);
        GLuint create (const std::string& source, GLenum type);
    
        std::string title;
    
        GLuint programID;
        GLuint vertexShaderID;
        GLuint geometryShaderID;
        GLuint fragmentShaderID;
};


#endif /* ComplexMaterial_hpp */
