//
//  HeightMap.hpp
//  WorldGenerator
//
//  Created by user on 15/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef HeightMap_hpp
#define HeightMap_hpp

#include "glew.h"
#include <string>

class HeightMap {
    public:
        HeightMap (std::string name);
       ~HeightMap ();
    
        GLfloat getHeightAt (GLuint u, GLuint v);
        GLuint getID ();
    
    private:
        int width;
        int height;
    
        GLuint textureID;
    
        unsigned char* data;
    
};

#endif /* HeightMap_hpp */
