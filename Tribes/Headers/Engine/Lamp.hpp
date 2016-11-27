#ifndef Lamp_hpp
#define Lamp_hpp

#include "Cube.hpp"
#include "ShaderCache.hpp"

class Lamp: public Cube {
    public:
        Lamp() {
            dropComponent(shader->componentID);
            shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("lightSource"));
        }
    
       ~Lamp() {}
    
        void explore (double animationTimer) {
            GLfloat radius = 6.0f;
            position.x = sin(animationTimer) * radius;
            position.z = cos(animationTimer) * radius;
        }
};

#endif
