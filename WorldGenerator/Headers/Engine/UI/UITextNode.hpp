//
//  UITextNode.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UITextNode_hpp
#define UITextNode_hpp

#include "GraphicsEngine.hpp"
#include "GameObject.hpp"
#include "Material.hpp"

#include <include/ft2build.h>
#include FT_FREETYPE_H

#include <vector>
#include <map>

class UITextNode: public GameObject {
    public:
        UITextNode (GraphicsEngine* graph);
       ~UITextNode ();
    
        virtual void update () override;
    
        void fadeIn  ();
        void fadeOut ();
    
        void renderText (std::string text, glm::vec2 position, glm::vec4 colour, float scale) {
            DrawCall call;
        
            call.text  = text;
            call.pos   = position;
            call.col   = colour;
            call.scale = scale;
        
            drawQueue.push_back(call);
        }
    
    private:
        struct Character {
            GLuint     textureID;  // ID handle of the glyph texture
            glm::ivec2 Size;       // Size of glyph
            glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
            GLuint     Advance;    // Offset to advance to next glyph
        };
    
        struct DrawCall {
            std::string text;
            glm::vec2 pos;
            glm::vec4 col;
            float scale;
        };
    
        Material material;
    
        glm::vec3 litColour;
        glm::vec3 unlitColour;
    
        FT_Library ft;
        FT_Face face;
    
        std::map<GLchar, Character> charmap;
        std::vector<DrawCall> drawQueue;
    
        GLuint VAO;
        GLuint VBO;
    
};

#endif /* UITextNode_hpp */
