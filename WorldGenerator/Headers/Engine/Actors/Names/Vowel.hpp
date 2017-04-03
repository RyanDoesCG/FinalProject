//
//  Vowel.hpp
//  MarkovNameMaker
//
//  Created by Ryan Needham on 28/03/2017.
//  Copyright © 2017 Ryan Needham. All rights reserved.
//

#ifndef Vowel_hpp
#define Vowel_hpp

#include "Letter.hpp"
#include <iostream>
#include <vector>

class Vowel : public Letter {
    public:
        Vowel () { val = possibleVals[rand() % max]; }
       ~Vowel () {}
    
        char value () override { return val; }
        int  type  () override { return 1; }
    
    private:
        std::vector<char> possibleVals = {
            'a', 'e', 'i', 'o', 'u'
        };
    
        unsigned int max = 5;
        char val;
};

#endif /* Vowel_hpp */
