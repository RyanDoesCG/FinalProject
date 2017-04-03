//
//  Flag.hpp
//  WorldGenerator
//
//  Created by user on 25/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Flag_hpp
#define Flag_hpp

#include "Random.hpp"
#include "GameObject.hpp"

class Flag {
    public:
        Flag () {
            colour = glm::vec4(fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), fmod(unsignedRand(), unsignedRand()), 1.0);
            ID = 1 + (rand() % 8);
        }
    
       ~Flag () {}
    
        glm::vec4 getColour () { return colour; }
        int getID () { return ID; }
    
    private:
        glm::vec4 colour;
        int ID;
    
};

#endif /* Flag_hpp */
