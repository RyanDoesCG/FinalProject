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
#include "Flag.hpp"
#include "MarkovGenerator.hpp"

// PUT PLANET UI IN HERE

class dioramaHUD: public GameHUD {
    public:
        dioramaHUD (GraphicsEngine* graph, PhysicsEngine* phys, Diorama* d);
       ~dioramaHUD ();
    
        virtual void update (State state) override;
        virtual void hide   () override;
        virtual void show   () override;
    
        Flag            flagData;
        std::string     name;
        GraphicsObject* flag;
        UIBox           heightMap;
        UISlider        amplitude;

        Diorama* diorama;
    
    private:
    
        GraphicsEngine* engine;
};


#endif /* dioramaHUD_hpp */
