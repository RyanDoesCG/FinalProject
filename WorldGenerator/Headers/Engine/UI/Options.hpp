//
//  Options.hpp
//  WorldGenerator
//
//  Created by user on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Options_hpp
#define Options_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"
#include "UIBox.hpp"

class Options: public GameObject {
    public:
        Options (GraphicsEngine* graph, PhysicsEngine* phys);
       ~Options ();
    
        virtual void update (State state) override;
    
        void hide ();
        void show ();
    
        UIBox resolution;
        UIBox sound;
        UIBox about;
        UIBox back;
    
    public:
        std::vector<UIBox*> items;
};

#endif /* Options_hpp */
