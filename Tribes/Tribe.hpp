/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Tribe.hpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Tribe_hpp
#define Tribe_hpp

#include "GameObject.hpp"
#include <iostream>

class Tribe : GameObject {
    public:
        Tribe  ();
        ~Tribe ();
    
        std::string* toString ();

    private:

};

#endif /* Tribe_hpp */
