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

enum Ethos {
    Warriors,
    Scientists,
    Traders,
    Ferals,
    ETHOS_MAX
};

class Tribe : GameObject {
    public:
        Tribe  ();
        ~Tribe ();
    
        std::string getName       ();
        Ethos       getEthos      ();
//      Flag        getFlag       ();
        int         getPopulation ();
    
        std::string toString ();

    private:
        std::string name;       // proc
        Ethos       ethos;      // proc
//      Flag        flag;       // proc
        int         population; // proc then modelled
    
        // Procedural Generators for more complicated data
        std::string generateName ();
//      Flag        generateFlag ();
};

#endif /* Tribe_hpp */
