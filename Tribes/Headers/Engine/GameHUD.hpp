/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameHUD.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GameHUD_hpp
#define GameHUD_hpp

#include "KeyboardComponent.hpp"
#include "TextRenderingComponent.hpp"
#include "Actor.hpp"
#include "Quad.hpp"

#include "Player.hpp"
#include "Planet.hpp"

class GameHUD : public Actor {
    public:
        GameHUD  (float width, float height, Game* game, Player* player, Planet* planet);
        ~GameHUD ();
    
        virtual void update (GameState state, SceneCamera* camera) override;

    
    private:
        float windowWidth;
        float windowHeight;
    
        Game* game;
    
        KeyboardCopmonent* keyboard;
        TextRenderingComponent* textPipeline;
    
        Quad leftUI;
        Quad rightUI;
    
        Quad menubarTop;
        Quad menubarBottom;
    
        Player* player;
        Planet* planet;
};

#endif /* GameHUD_hpp */
