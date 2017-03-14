//
//  Texture.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <iostream>
#include "glew.h"

class Texture {
    public:
        Texture (std::string name);
        Texture (GLuint id);
        Texture ();
       ~Texture ();
    
        void bind   ();
        void unbind ();
    
        void setID ();
    
    private:
    
        GLuint textureID;
    
};

#endif /* Texture_hpp */
