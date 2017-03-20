//
//  dioramaHUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef dioramaHUD_hpp
#define dioramaHUD_hpp

#include "UISlider.hpp"
#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameHUD.hpp"
#include "Diorama.hpp"
#include "UIPlusMinus.hpp"

class dioramaHUD: public GameHUD {
    public:
        dioramaHUD (GraphicsEngine* graph, PhysicsEngine* phys, Diorama* d);
       ~dioramaHUD ();
    
        virtual void update (State state) override;
        virtual void hide   () override;
        virtual void show   () override;
    
        UISlider renderDistance;
        UISlider amplitude;
        UISlider seaLevel;
        UISlider example3;
        UISlider example4;

        Diorama* diorama;
};


#endif /* dioramaHUD_hpp */
