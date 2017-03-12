//
//  Menu.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"
#include "UIBox.hpp"

class Menu: public GameObject {
    public:
        Menu (GraphicsEngine* graph, PhysicsEngine* phys);
       ~Menu ();
    
        virtual void update () override;
    
        void hide ();
        void show ();
    
        UIBox dioramas;
        UIBox planets;
        UIBox options;
        UIBox quit;
    
    public:
        std::vector<UIBox*> items;
    
};

#endif /* Menu_hpp */
