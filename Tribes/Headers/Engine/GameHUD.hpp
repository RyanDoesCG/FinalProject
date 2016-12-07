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

class GameHUD : public Actor {
    public:
        GameHUD  (float width, float height, Game* game);
        ~GameHUD ();
    
        virtual void update (GameState state, SceneCamera* camera) override;

    
    private:
        float windowWidth;
        float windowHeight;
    
        Game* game;
    
        KeyboardCopmonent* keyboard;
        TextRenderingComponent* textPipeline;
};

#endif /* GameHUD_hpp */
