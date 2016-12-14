/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  KeyboardComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef KeyboardComponent_hpp
#define KeyboardComponent_hpp

#include "Component.hpp"
#include "../Core/Game.hpp"

class KeyboardComponent : public Component {
    public:
        KeyboardComponent ();
       ~KeyboardComponent ();
    
        void attach (GLFWwindow* window);
    
        virtual void init() override;
        virtual void update() override;
    
        bool isKeyDown (int keycode);
        void keyHandled (int keycode);
    
};

#endif /* KeyboardComponent_hpp */
