//
//  TextGeometry.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef TextGeometry_hpp
#define TextGeometry_hpp

#include "Geometry.hpp"
#include <include/ft2build.h>
#include FT_FREETYPE_H

#include "TextDrawCall.hpp"

class TextGeometry: public Geometry {
    public:
        TextGeometry();
       ~TextGeometry();
    
        void print (TextDrawCall text);
    
        void setup  () override;
        void render () override;
    
    private:
        FT_Library ft;
        FT_Face  face;
    
        std::vector<TextDrawCall> calls;
};

#endif /* TextGeometry_hpp */
