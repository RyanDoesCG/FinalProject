#ifndef Lamp_hpp
#define Lamp_hpp

#include "Model.hpp"
#include "ShaderCache.hpp"

class Lamp: public Model {
    public:
        Lamp() : Model("sphere/sphere") {
            shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource"));
            setScale(0.2);
            lightSource = this;
        }
    
       ~Lamp() {}

};

#endif
