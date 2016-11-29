#ifndef Lamp_hpp
#define Lamp_hpp

#include "Cube.hpp"
#include "ShaderCache.hpp"

class Lamp: public Cube {
    public:
        Lamp() {
            dropComponent(shader->componentID);
            shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource"));
            
            lightSource = this;
        }
    
       ~Lamp() {}

};

#endif
