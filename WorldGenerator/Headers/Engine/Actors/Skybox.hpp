/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Skybox.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Skybox_hpp
#define Skybox_hpp

#include "Cube.hpp"
#include <iostream>

class Skybox : public Cube {
public:
    Skybox  ();
    ~Skybox ();
    
    virtual void draw (SceneCamera* camera) override;
    virtual void update (GameState state) override;
    
private:
    
};

#endif /* Skybox_hpp */
