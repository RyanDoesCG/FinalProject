/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Backdrop.hpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
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

};

#endif /* Backdrop_hpp */
