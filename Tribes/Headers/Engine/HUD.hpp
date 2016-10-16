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

class Quad {
    
};

class HUD : public GameObject {
    public:
        HUD  (Game* g, int width, int height, float* d);
        HUD  (Game* g, int width, int height);
        ~HUD ();
    
        virtual void update ();
    
        void updateMousePosition (float x, float y);

    private:
        TextRenderer textPipeline;

        const int screenWidth;
        const int screenHeight;
    
        float mouseX;
        float mouseY;
        
        Game* game;
        float* delta;

};

#endif /* HUD_hpp */
