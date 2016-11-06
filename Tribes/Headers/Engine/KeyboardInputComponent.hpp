/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardInputComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef KeyboardInputComponent_hpp
#define KeyboardInputComponent_hpp

#include "ActorComponent.hpp"
#include "Game.hpp"

class KeyboardInputComponent : public ActorComponent {
public:
     KeyboardInputComponent (GLFWwindow* window, Game* game);
    ~KeyboardInputComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
    bool isKeyDown (int keycode);
//    void keyHandled (int keycode);
    
private:
    GLFWwindow* window;
    Game* game;
    
};

#endif /* KeyboardInputComponent_hpp */
