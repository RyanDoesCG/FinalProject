//
//  Letter.hpp
//  MarkovNameMaker
//
//  Created by Ryan Needham on 28/03/2017.
//  Copyright © 2017 Ryan Needham. All rights reserved.
//

#ifndef Letter_hpp
#define Letter_hpp

class Letter {
    public: virtual char value () = 0;
    public: virtual int  type  () = 0;
};

#endif /* Letter_hpp */
