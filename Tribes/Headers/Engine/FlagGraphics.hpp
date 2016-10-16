/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  FlagGraphics.hpp
 *  Tribes
 *
 *  Created by user on 15/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef FlagGraphics_hpp
#define FlagGraphics_hpp

#include "GraphicsComponent.hpp"
#include <iostream>

/**
 *  FlagGraphics Class
 *
 */
class FlagGraphics : public GraphicsComponent {
    public:
        FlagGraphics  ();
        ~FlagGraphics ();

    virtual void draw();
    
    private:

};

#endif /* FlagGraphics_hpp */
