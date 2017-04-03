//
//  Consonant.hpp
//  MarkovNameMaker
//
//  Created by Ryan Needham on 28/03/2017.
//  Copyright © 2017 Ryan Needham. All rights reserved.
//

#ifndef Consonant_hpp
#define Consonant_hpp

#include "Letter.hpp"
#include <iostream>
#include <vector>

class Consonant : public Letter {
    public:
        Consonant () { val = possibleVals[rand() % max]; }
       ~Consonant () {}
    
        char value () override { return val; }
        int  type  () override { return 0; }
    
    private:
        std::vector<char> possibleVals = {
            'b', 'c', 'd', 'f', 'g',
            'h', 'j', 'k', 'l', 'm',
            'n', 'p', 'q', 'r', 's',
            't', 'v', 'w', 'x', 'y',
            'z'
        };
    
        unsigned int max = 21;
        char val;
};

#endif /* Consonant_hpp */
