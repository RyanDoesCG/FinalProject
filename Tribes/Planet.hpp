/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.hpp
 *  Tribes
 *
 *  Created by ryan needham on 06/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 *  Both regions and tribes can be "Wiped from the face of
 *  the earth"
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Planet_hpp
#define Planet_hpp

#include "GameObject.hpp"
#include "Biome.hpp"
#include "Tribe.hpp"
#include <iostream>
#include <vector>

enum Difficulty {
    TOUGH,
    TOUGHER,
    TOUGHEST
};

class Planet : public GameObject {
    public:
        Planet  (Difficulty difficulty);
        ~Planet ();
    
        inline Difficulty getDifficulty () { return difficulty; }
        inline int        getBiomeCount () { return biomeCount; }
        inline int        getTribeCount () { return tribeCount; }
    
        void draw () { this->render(); }
    
        std::string toString ();

    private:
        Difficulty difficulty;
        int biomeCount;
        int tribeCount;
    
        std::vector<Biome*> regions;
        std::vector<Tribe*> tribes;
};

#endif /* Planet_hpp */
