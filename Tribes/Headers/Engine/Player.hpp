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
#include "KeyboardInputComponent.hpp"
#include "MouseInputComponent.hpp"

#include "Game.hpp"

#include <iostream>

class Player : public Actor {
public:
     Player (GLFWwindow* window, Game* game);
    ~Player ();

    virtual void init() override;
    virtual void update() override;
    
private:
    MouseInputComponent* mouse;
    KeyboardInputComponent* keyboard;
    
};

#endif /* Player_hpp */
