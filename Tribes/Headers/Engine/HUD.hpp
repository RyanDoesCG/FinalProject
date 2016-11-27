/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef HUD_hpp
#define HUD_hpp

#include "Actor.hpp"
#include "Game.hpp"
#include "TextRenderingComponent.hpp"
#include "KeyboardInputComponent.hpp"
#include "MouseInputComponent.hpp"
#include <iostream>
#include <vector>

class HUD : public Actor {
    public:
        HUD (GLFWwindow* window, Game* game);
       ~HUD ();
    
        virtual void init() override;
        virtual void update(GameState state, SceneCamera* camera) override;
    
    private:
        Game* game;
    
        MouseInputComponent* mouse;
        KeyboardInputComponent* keyboard;
        TextRenderingComponent* textRenderer;

};

#endif /* HUD_hpp */
