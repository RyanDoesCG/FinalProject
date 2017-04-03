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
#include "UISlider.hpp"
#include "UIPlusMinus.hpp"
#include "GameHUD.hpp"
#include "Planet.hpp"
#include "Flag.hpp"

// REPLICATE IN DIORAMA HUD

class planetHUD: public GameHUD {
    public:
        planetHUD (GraphicsEngine* graph, PhysicsEngine* phys, Planet* p);
       ~planetHUD ();
    
        virtual void update (State state) override;
        virtual void hide   () override;
        virtual void show   () override;
    
        Flag            flagData;
        std::string     name;
        GraphicsObject* flag;
        UIBox           metaData;
        UIBox           heightMap;
        UISlider        amplitude;
    
        Planet* planet;
    
    private:
    
        GraphicsEngine* engine;
};


#endif /* planetHUD_hpp */
