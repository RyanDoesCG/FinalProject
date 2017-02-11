//
//  HeightMap.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef HeightMap_hpp
#define HeightMap_hpp

#include "../../glew/glew.h"
#include "../../FastNoise/FastNoise.h"
#include <vector>

class HeightMap {
    public:
        HeightMap (int width, int height);
       ~HeightMap ();
    
        void generate    ();
        void bind        ();
        void writeToDisk ();
    
        GLuint getID () {return textureID;}
    
    private:
        const int width;
        const int height;
    
        GLuint  textureID;
        GLfloat * textureData;
    
        FastNoise noiseGenerator;
};

#endif /* HeightMap_hpp */
