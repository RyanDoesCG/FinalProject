/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextureComponent.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TextureComponent_hpp
#define TextureComponent_hpp

#include "ActorComponent.hpp"
#include "../GLEW/glew.h"
#include "../GLFW/glfw3.h"
#include <iostream>

class TextureComponent : public ActorComponent {
public:
     TextureComponent (std::string path);
    ~TextureComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
private:
    int width;
    int height;
    unsigned char* imageData;
    
    GLuint textureID;
    std::string title;
};

#endif /* TextureComponent_hpp */
