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
#include "../GLFW/glfw3.h"

class MouseInputComponent : public ActorComponent {
    public:
        MouseInputComponent ();
       ~MouseInputComponent ();

        virtual void init() override;
        virtual void update() override;
};

#endif /* MouseInputComponent_hpp */
