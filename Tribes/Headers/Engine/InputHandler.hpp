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

class Game;

/**
 *  InputHandler Class
 *
 */
class InputHandler {
    public:
        InputHandler  (Game* g);
        ~InputHandler ();

        void update();
    
    private:
        Game* game;
    
        void populateInputArray();
        void processInputArray();
};

#endif /* InputHandler_h */
