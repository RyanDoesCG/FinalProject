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

class Game;
class InputHandler {
    public:
        InputHandler  (Game* g);
        ~InputHandler ();

        void checkInput();
    
    private:
        Game*     game;
    
};

#endif /* InputHandler_h */
