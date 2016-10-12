/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Texture.hpp
 *  Tribes
 *
 *  Created by user on 16/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Texture_hpp
#define Texture_hpp

#include "../glew/glew.h"
#include "../glfw/glfw3.h"
#include "../soil/SOIL.h"
#include <iostream>

class Texture {
    public:
        Texture(std::string path);
        ~Texture();
    
        void bind();
    
    private:
        int width;
        int height;
    
        GLuint textureID;
    
        unsigned char* image;
};

#endif /* Texture_hpp */
