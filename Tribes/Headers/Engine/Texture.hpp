/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Texture.hpp
 *  Tribes
 *
 *  Created by user on 16/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Texture_hpp
#define Texture_hpp

#include "../GLEW/glew.h"
#include "../GLFW/glfw3.h"
#include "../SOIL/SOIL.h"
#include <iostream>

class Texture {
    public:
        Texture(std::string path);
        ~Texture();
    
        void bind();
    
        std::string getTextureTitle();
    
    private:
        int width;
        int height;
        unsigned char* image;
    
        GLuint textureID;
        std::string title;
    
};

#endif /* Texture_hpp */
