/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ShaderComponent_hpp
#define ShaderComponent_hpp

#include "ActorComponent.hpp"

class ShaderComponent : public ActorComponent {
    public:
         ShaderComponent ();
        ~ShaderComponent ();
    
        virtual void init() override;
        virtual void update() override;
};

#endif /* ShaderComponent_hpp */
