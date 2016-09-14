/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Biome_hpp
#define Biome_hpp

#include "GameObject.hpp"
#include <iostream>

/** 
 *  Vegitation type should be generated based on
 *  weather. 
 *      - snow makes evergreens
 *      - desert makes palm trees
 *      - normal makes oak
 *      - volcanic makes burnt out trunks
 *
 *  Every biome should have at least enough wood/materials
 *  for the player to build a boat and reach another biome.
 */
enum Weather {
    Volcanic,
    Desert,
    Snow,
    Normal,
    WEATHER_MAX
};

enum Landscape {
    Mountainous,
    Hilly,
    Flatlands,
    LANDSCAPE_MAX
};

enum Resources {
    Bronze,
    Iron,
    Steel,
    Alluminium,
    Diamond,
    RESOURCE_MAX
};

enum Vegitation {
    Sparse,
    Moderate,
    Plentiful,
    VEGITATION_MAX
};

class Biome : GameObject {
    public:
        Biome  ();
        ~Biome ();
    
        inline Weather    getWeatherType       ();
        inline Landscape  getLandscapeType     ();
        inline Vegitation getVegitationType    ();
        inline Resources  getAuxResourcesType  ();
        inline Resources  getMainResourcesType ();
    
        std::string toString ();
    
    private:
        Weather    weather;
        Landscape  landscape;
        Vegitation vegitation;
        Resources  auxResource;
        Resources  mainResource;
    
        int viability;
    
        // need some kind of score on how
        // accomodating to life a biome is
        // based on the above parameters.
};

#endif /* Biome_hpp */
