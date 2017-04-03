//
//  MarkovGenerator.hpp
//  MarkovNameMaker
//
//  Created by Ryan Needham on 28/03/2017.
//  Copyright © 2017 Ryan Needham. All rights reserved.
//

#ifndef MarkovGenerator_hpp
#define MarkovGenerator_hpp

#include "Consonant.hpp"
#include "Vowel.hpp"
#include <string>

class MarkovGenerator {
    public:
        static std::string generate (int length);
};

#endif /* MarkovGenerator_hpp */
