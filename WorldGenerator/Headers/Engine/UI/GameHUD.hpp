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

#include "../Components/KeyboardComponent.hpp"
#include "../Components/TextRenderingComponent.hpp"
#include "../Actors/Actor.hpp"
#include "../Actors/Quad.hpp"

#include "../Actors/Player.hpp"
#include "../Actors/Planet.hpp"

class GameHUD : public Actor {
    public:
        GameHUD  (float width, float height, Game* game, Player* player, Planet* planet);
        ~GameHUD ();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
    private:
        float windowWidth;
        float windowHeight;
    
        Game* game;
    
        GamepadComponent*       gamepad;
        KeyboardCopmonent*      keyboard;
        TextRenderingComponent* textPipeline;
    
        Quad leftUI;
        Quad rightUI;
    
        Quad menubarTop;
        Quad menubarBottom;
    
        Player* player;
        Planet* planet;
    
        int mode = 0; // 0 - explore / 1 - edit
};

#endif /* GameHUD_hpp */
