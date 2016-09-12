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

class Flag {
    public:
        Flag() {}
        ~Flag() {}
    
    private:
    
    
};

class Tribe : GameObject {
    public:
        Tribe  ();
        ~Tribe ();
    
        std::string getName       ();
        Ethos       getEthos      ();
        Flag        getFlag       ();
        int         getPopulation ();
    
        std::string toString ();

    private:
        std::string name;
        Ethos       ethos;
        Flag        flag;
        int         population;
    
        // Procedural Generators for more complicated data
        void        generateName ();
        void        generateFlag ();
};

#endif /* Tribe_hpp */
