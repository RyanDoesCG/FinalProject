/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardCopmonent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef KeyboardCopmonent_hpp
#define KeyboardCopmonent_hpp

#include "ActorComponent.hpp"
#include "Game.hpp"

class KeyboardCopmonent : public ActorComponent {
    public:
        KeyboardCopmonent (GLFWwindow* window, Game* game);
       ~KeyboardCopmonent ();
    
        virtual void init() override;
        virtual void update() override;
    
        bool isKeyDown (int keycode);
        void keyHandled (int keycode);
    
    private:
        GLFWwindow* window;
        Game* game;
};

#endif /* KeyboardCopmonent_hpp */
