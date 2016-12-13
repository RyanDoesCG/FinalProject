#ifndef ColourPalette_hpp
#define ColourPalette_hpp

#include "../../glm/glm.hpp"
#include <string>
#include <map>

enum ColourID {
    Black,
    White,
    LightGray,
    Gray,
    DarkGray,
    Sand,
    Red,
    COLOUR_LIMIT
};

class ColourPalette {
    public:
        typedef std::pair<ColourID, glm::vec3> Colour;
    
        static glm::vec3 getColour (ColourID id) { return palette.at(id); }
        static glm::vec3 getAnyColour () { return palette.at((ColourID)(rand() % COLOUR_LIMIT)); }
    
    private:
        static const std::map<ColourID, glm::vec3> palette;
};

#endif /* ColourPalette.hpp */
