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
#include "Flag.hpp"
#include <iostream>
#include <vector>

//      /|\         /\      \\
//     /_|_\       /  \     \\
//     \ | /       \  /     \\
//      \|/         \/      \\

enum Difficulty {
    TOUGH,
    TOUGHER,
    TOUGHEST
};

/** 
 *  Planet Class
 */
class Planet : public GameObject {
    public:
        Planet  (Difficulty difficulty, long seed);
        ~Planet ();
    
        inline Difficulty  getDifficulty () { return difficulty; }
        inline int         getBiomeCount () { return biomeCount; }
        inline int         getTribeCount () { return tribeCount; }
        inline Flag*       getFlag       () { return galacticFlag;}
        inline std::string getName       () { return name; }
    
        std::string toString ();
    
        void rotateLeft  () { graphics->rotateLeft(); }
        void rotateRight () { graphics->rotateRight(); }
        void grow        () { graphics->grow(); }
        void shrink      () { graphics->shrink(); }
    
        void randomise ();
    
        void generateName   ();
        void generateFlag   ();
        void generateBiomes ();

    private:
        Difficulty difficulty;
        int        biomeCount;
        int        tribeCount;
    
        Flag* galacticFlag = nullptr;
    
        std::vector<Biome*> regions;
        std::vector<Tribe*> tribes;
    
        std::string name;
};

#endif /* Planet_hpp */
