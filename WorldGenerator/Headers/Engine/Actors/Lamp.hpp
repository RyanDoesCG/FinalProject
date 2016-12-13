/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Lamp.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Lamp_hpp
#define Lamp_hpp

#include "Model.hpp"
#include "../Utility/ShaderCache.hpp"

class Lamp: public Model {
    public:
        Lamp() : Model("sphere/sphere") {
            shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource", BASIC));
            setScale(0.2);
            lightSource = this;
        }
    
       ~Lamp() {}

};

#endif
