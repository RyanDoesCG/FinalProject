//
//  Showcase.hpp
//  Tribes
//
//  Created by user on 09/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#ifndef Showcase_hpp
#define Showcase_hpp

#include "../../GLEW/glew.h"
#include "../../GLFW/glfw3.h"

class Showcase {
    public:
        Showcase ();
       ~Showcase ();
    
    void begin();
    void pause();
    void end();
    
    inline int getSeed ();
    inline void setSeed (int s) {seed = s;}
    
    bool windowIsAlive();
    
    int windowWidth;
    int windowHeight;
    
private:
    typedef int actorID;
    
    int initGLFW ();
    int initGLEW ();
    
    GLFWwindow* window;
    
    // world seed
    int generateSeed();
    int seed;
};

#endif /* Showcase_hpp */
