/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Flag.hpp
 *  ShaderToy
 *
 *  Created by ryan needham on 15/10/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Flag_hpp
#define Flag_hpp

#include "GameObject.hpp"

class Flag : public GameObject {
    public:
        Flag();
        ~Flag();
    
        void generateFlag ();
};

#endif
