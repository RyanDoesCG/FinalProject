#ifndef ColourPalette_hpp
#define ColourPalette_hpp

#include "../glm/glm.hpp"
#include <string>
#include <map>

class ColourPalette {
    public:
        ColourPalette ();
       ~ColourPalette ();
    
        glm::vec3 getColour (std::string name);
        glm::vec3 getAnyColour ();
    
    private:
        std::map<std::string, glm::vec3> palette;
};

#endif /* ColourPalette.hpp */
