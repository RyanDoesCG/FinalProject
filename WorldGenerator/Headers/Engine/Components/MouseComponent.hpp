/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MouseComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MouseComponent_hpp
#define MouseComponent_hpp

#include "Component.hpp"
#include "../Core/Game.hpp"

class MouseComponent : public Component {
    public:
        MouseComponent (GLFWwindow* window, Game* game);
       ~MouseComponent ();

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

#endif /* MouseComponent_hpp */
