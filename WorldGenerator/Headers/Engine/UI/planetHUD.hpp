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
#include "Planet.hpp"

class planetHUD: public GameHUD {
    public:
        planetHUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~planetHUD ();
    
        virtual void update (State state) override;
        virtual void hide   () override;
        virtual void show   () override;
    
        Planet* planet;
};


#endif /* planetHUD_hpp */