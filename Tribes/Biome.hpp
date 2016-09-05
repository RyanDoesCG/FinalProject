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

#include <iostream>

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
    None,
    Sparse,
    Moderate,
    Plentiful,
    VEGITATION_MAX
};

class Biome {
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
        int hospitability;
    
        Weather    weather;
        Landscape  landscape;
        Vegitation vegitation;
        Resources  auxResource;
        Resources  mainResource;
};

#endif /* Biome_hpp */
