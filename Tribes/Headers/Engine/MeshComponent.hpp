/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MeshComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MeshComponent_hpp
#define MeshComponent_hpp

#include "ActorComponent.hpp"

class MeshComponent : public ActorComponent {
    public:
         MeshComponent ();
        ~MeshComponent ();
    
        virtual void init() override;
        virtual void update() override;
};

#endif /* MeshComponent_hpp */
