//
//  Material.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <iostream>
#include "glm.hpp"
#include "glew.h"

class Material {
    public:
        Material(const std::string& name);
       ~Material();
    
        void bind();
    
        GLuint getProgramID();
        std::string getTitle();
    
    private:
        glm::vec4 colour;
    
        std::string load (const std::string& path);
        GLuint create (const std::string& source, GLenum type);
    
        std::string title;
};

#endif /* Material_hpp */
