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
        Material(Shader* shader, std::string textureName);
        Material(Shader* shader, GLuint textureID);
        Material(Shader* shader);
       ~Material();
    
        void bind   ();
        void unbind ();
    
        GLuint getProgramID();
        std::string getTitle();
    
        void setTexture (GLuint id);
    
    private:
        glm::vec4 colour;

        Shader* shader;
        Texture texture;
};

#endif /* Material_hpp */
