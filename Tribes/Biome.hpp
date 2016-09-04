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
    Snow,
    Desert,
    Normal,
    WEATHER_MAX
};

enum Landscape {
    Mountainous,
    Flatlands,
    Hilly,
    LANDSCAPE_MAX
};

enum Vegitation {
    Plentiful,
    Moderate,
    Sparse,
    VEGITATION_MAX
};

class Biome {
    public:
        Biome();
        ~Biome();
    
        inline Weather getWeatherType () { return weather; }
        inline Landscape getLandscapeType () { return landscape; }
        inline Vegitation getVegitationType () { return vegitation; }
    
        std::string toString();
    
    private:
        Weather weather;
        Landscape landscape;
        Vegitation vegitation;
};

#endif /* Biome_hpp */
