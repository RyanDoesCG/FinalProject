/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Player.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Player_hpp
#define Player_hpp

#include "Actor.hpp"
#include "TextRenderingComponent.hpp"
#include "KeyboardComponent.hpp"
#include "MouseComponent.hpp"
#include "GamepadComponent.hpp"

#include "Game.hpp"

#include <iostream>

class Player : public Actor {
    public:
        Player (GLFWwindow* window, Game* game);
       ~Player ();

        SceneCamera* getView () {return this->camera;}
    
        virtual void init() override;
        virtual void update(GameState state, SceneCamera* camera) override;
    
    private:
        SceneCamera*            camera;
        GamepadComponent*       gamepad;
        MouseComponent*    mouse;
        KeyboardCopmonent* keyboard;
    
        Game* game;
    
        bool inGame;
};

#endif /* Player_hpp */
