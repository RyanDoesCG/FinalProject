/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.hpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PlanetGraphics_hpp
#define PlanetGraphics_hpp

#include "GraphicsComponent.hpp"
#include "../GLM/glm.hpp"
#include <iostream>

class PlanetGraphics : public GraphicsComponent {
    public:
        PlanetGraphics  ();
        ~PlanetGraphics ();
    
        virtual void draw();
    
    private:
};

#endif /* PlanetGraphics_hpp */
