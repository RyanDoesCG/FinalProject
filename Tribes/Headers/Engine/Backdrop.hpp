/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Backdrop.hpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Backdrop_hpp
#define Backdrop_hpp

#include "GameObject.hpp"
#include <iostream>

class Backdrop : public GameObject {
    public:
        Backdrop  (int quality);
        ~Backdrop ();
    
        virtual void update();
    
    void rotateLeft  () { graphics->rotateLeft(); }
    void rotateRight () { graphics->rotateRight(); }
    void grow        () { graphics->grow(); }
    void shrink      () { graphics->shrink(); }

    private:

};

#endif /* Backdrop_hpp */
