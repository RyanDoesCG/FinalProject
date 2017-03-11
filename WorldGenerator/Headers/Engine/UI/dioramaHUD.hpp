//
//  dioramaHUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef dioramaHUD_hpp
#define dioramaHUD_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameHUD.hpp"


class dioramaHUD: public GameHUD {
    public:
        dioramaHUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~dioramaHUD ();
    
        virtual void update () override;
        virtual void hide   () override;
        virtual void show   () override;

};


#endif /* dioramaHUD_hpp */
