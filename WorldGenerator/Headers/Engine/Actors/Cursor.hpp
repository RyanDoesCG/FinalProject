/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Cursor.hpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 14/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Cursor_hpp
#define Cursor_hpp

#include "Actor.hpp"
#include "../Components/MouseComponent.hpp"
#include "../Components/GamepadComponent.hpp"

class Cursor : public Actor {
    public:
        Cursor (GLFWwindow* window, Game* game);
       ~Cursor ();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
    private:
        MouseComponent* mouse;
        GamepadComponent* gamepad;
    
};

#endif /* Cursor_hpp */
