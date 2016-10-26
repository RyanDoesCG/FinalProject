/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.hpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef HUD_hpp
#define HUD_hpp

#include "TextRenderer.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

#include "../GLFW/glfw3.h"

/**
 *  Quad Class
 *
 */
class Quad {
    
};

/**
 *  HUD Class
 *
 */
class HUD : public GameObject {
    public:
        HUD  (Game* g, float* d);
        HUD  (Game* g);
        HUD  ();
        ~HUD ();
    
        virtual void update ();
    
        void updateMousePosition (float x, float y);

    private:
        TextRenderer textPipeline;

        int screenWidth;
        int screenHeight;
    
        float mouseX;
        float mouseY;
    
        float* delta;
        Game* game;

};

#endif /* HUD_hpp */
