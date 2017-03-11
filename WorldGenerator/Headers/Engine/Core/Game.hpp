//
//  Game.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "InputManager.hpp"
#include "Window.hpp"

class Game {
    public:
        Game ();
       ~Game ();
    
        void boot ();
        void stop ();
    
    protected:
        GraphicsEngine graphics;
        PhysicsEngine  physics;
    
        InputManager input;
        Window window;
    
};

#endif /* Game_hpp */
