/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUDElement.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 06/11/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef HUDElement_hpp
#define HUDElement_hpp

#include "TextRenderingComponent.hpp"
#include "ShaderComponent.hpp"
#include "Actor.hpp"

class HUDElement : public Actor {
    public:
         HUDElement (std::string t, glm::vec2 p);
        ~HUDElement ();
    
        virtual void init() override;
        virtual void update(GameState state) override;
    
        void select   ();
        void unselect ();
    
    private:
        glm::vec2 position;
        std::string text;
        GLuint selected;       // actually bool but GLSL wants an int
    
        std::vector<GLfloat> box;
    
        TextRenderingComponent* textRenderer;
        ShaderComponent* shader;
};

#endif /* HUDElement_hpp */
