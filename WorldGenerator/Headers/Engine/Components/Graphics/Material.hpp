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
#include "Shader.hpp"
#include "Texture.hpp"
#include "glm.hpp"
#include "glew.h"

class Material {
    public:
        Material(const std::string& shaderName, std::string textureName);
        Material(const std::string& shaderName, GLuint textureID); // for post-processor
        Material(const std::string& name);
       ~Material();
    
        void bind   ();
        void unbind ();
    
        GLuint getProgramID();
        std::string getTitle();
    
    private:
        glm::vec4 colour;

        Shader shader;
        Texture texture;
};

#endif /* Material_hpp */
