//
//  HUD.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef HUD_hpp
#define HUD_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"

#include "InputManager.hpp"
#include "Mouse.hpp"
#include "UIBoxBackground.hpp"
#include "UIBox.hpp"

class HUD: public GameObject {
    public:
        HUD (GraphicsEngine* graph, PhysicsEngine* phys);
       ~HUD ();
    
        virtual void update () override;
    
        void hide ();
        void show ();
    
    public:
        UIBoxBackground background;
        std::vector<UIBox> items;
    
        Mouse* mouse;
};


#endif /* HUD_hpp */
