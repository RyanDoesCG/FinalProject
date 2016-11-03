/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextureComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TextureComponent_hpp
#define TextureComponent_hpp

#include "ActorComponent.hpp"

class TextureComponent : public ActorComponent {
    public:
         TextureComponent ();
        ~TextureComponent ();
    
        virtual void init() override;
        virtual void update() override;
};

#endif /* TextureComponent_hpp */
