//
//  Biome.hpp
//  Tribes
//
//  Created by ryan needham on 04/09/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//
#ifndef Biome_hpp
#define Biome_hpp

#include <iostream>

enum Weather {
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

enum Vegitation {
    Sparse,
    Moderate,
    Plentiful,
    VEGITATION_MAX
};

// exp.
enum Resources {
    Gold,
    Iron,
    Steel,
    Alluminium
};

class Biome {
    public:
        Biome();
        ~Biome();
    
        inline Weather getWeatherType ();
        inline Landscape getLandscapeType ();
        inline Vegitation getVegitationType ();
    
        std::string toString();
    
    private:
        int hospitability;
    
        Weather weather;
        Landscape landscape;
        Vegitation vegitation;
};

#endif /* Biome_hpp */
