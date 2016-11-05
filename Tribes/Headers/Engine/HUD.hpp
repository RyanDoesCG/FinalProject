/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  HUD.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef HUD_hpp
#define HUD_hpp

#include "Actor.hpp"
#include "../GLEW/glew.h"
#include <iostream>
#include <vector>

class HUD : public Actor {
public:
     HUD  ();
    ~HUD ();
    virtual void init() override;
    virtual void update() override;
    
private:
    std::vector<GLfloat> mainPane;
};

#endif /* HUD_hpp */
