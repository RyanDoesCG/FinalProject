/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  BackdropGraphics.hpp
 *  Tribes
 *
 *  Created by user on 16/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef BackdropGraphics_hpp
#define BackdropGraphics_hpp

#include "GraphicsComponent.hpp"
#include <iostream>

class BackdropGraphics : public GraphicsComponent {
    public:
        BackdropGraphics  (int quality);
        ~BackdropGraphics ();


        virtual void draw ();
    
    
        virtual void rotateLeft ();
        virtual void rotateRight ();
        virtual void grow ();
        virtual void shrink ();

};

#endif /* BackdropGraphics_hpp */
