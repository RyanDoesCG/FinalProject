//
//  planetHUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef planetHUD_hpp
#define planetHUD_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameHUD.hpp"

class planetHUD: public GameHUD {
    public:
        planetHUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~planetHUD ();
    
        virtual void update () override;
        virtual void hide   () override;
        virtual void show   () override;
};


#endif /* planetHUD_hpp */
