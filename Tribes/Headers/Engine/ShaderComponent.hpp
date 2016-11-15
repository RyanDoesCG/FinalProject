/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ShaderComponent_hpp
#define ShaderComponent_hpp

#include "ActorComponent.hpp"
#include "../GLEW/glew.h"
#include <iostream>

class ShaderComponent : public ActorComponent {
public:
     ShaderComponent (const std::string& name);
    ~ShaderComponent ();
    
    virtual void init() override;
    virtual void update() override;
    
    GLuint getProgramID();
    std::string getTitle(){return title;}
    
private:
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    
    std::string loadSource (const std::string& path);
    GLuint createShader (const std::string& source, GLenum type);
    
    std::string title;
};

#endif /* ShaderComponent_hpp */
