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

// MISSION: BECOME ABSTRACT

class Shader {
    public:
        Shader ();
       ~Shader ();
    
       void bind   ();
       void unbind ();
    
       GLuint getProgramID  ();
       std::string getTitle ();
    
    protected:
        std::string load (const std::string& path);
        GLuint compile   (const std::string& source, GLenum type);
        void checkErrors ();
    
        std::string title;
    
        GLuint programID;

};

#endif /* Shader_hpp */
