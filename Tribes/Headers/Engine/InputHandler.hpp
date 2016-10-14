/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  InputHandler.hpp
 *  Tribes
 *
 *  Created by ryan needham on 03/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <iostream>

#define KEYCOUNT 348

// Forward declaration as Game.hpp cannot be imported
class Game;
class InputHandler {
    public:
        InputHandler  (Game* g);
        ~InputHandler ();

        void update();
    
    private:
        Game* game;
    
        void checkInput();
        void processInput();
};

#endif /* InputHandler_h */
