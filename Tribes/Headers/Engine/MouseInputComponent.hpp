/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MouseInputComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MouseInputComponent_hpp
#define MouseInputComponent_hpp

#include "ActorComponent.hpp"
#include "Game.hpp"

class MouseInputComponent : public ActorComponent {
    public:
        MouseInputComponent (GLFWwindow* window, Game* game);
       ~MouseInputComponent ();

        virtual void init() override;
        virtual void update() override;
    
        void hideMouse ();
        void showMouse ();
    
        void placeMouse(int x, int y);
        void centerMouse();
    
        float getMouseX ();
        float getMouseY ();
    
        float getXoffset ();
        float getYoffset ();
    
    private:
        GLFWwindow* window;
        Game* game;
};

#endif /* MouseInputComponent_hpp */
