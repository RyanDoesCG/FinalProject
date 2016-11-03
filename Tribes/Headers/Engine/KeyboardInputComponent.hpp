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
#include "../GLFW/glfw3.h"

class KeyboardInputComponent : public ActorComponent {
    public:
         KeyboardInputComponent ();
        ~KeyboardInputComponent ();
    
        virtual void init() override;
        virtual void update() override;
};

#endif /* KeyboardInputComponent_hpp */
