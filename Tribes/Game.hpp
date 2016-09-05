/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.hpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Game_hpp
#define Game_hpp

#include "InputHandler.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include "Window.hpp"

#include <iostream>
#include <vector>

#define SCREEN_WIDTH  683
#define SCREEN_HEIGHT 384

class Game {
    public:
        Game  ();
        ~Game ();
    
        void begin ();
        void end ();
    
        void pause();

    private:
        enum State {
            RUNNING,
            PAUSED,
            ENDED
        };
    
        InputHandler* input;
        Window* window;
        Camera* camera;
        State state;
    
        std::vector<GameObject*> objectPool;
};

#endif /* Game_hpp */
