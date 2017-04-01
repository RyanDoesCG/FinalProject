//
//  Sun.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Sun_hpp
#define Sun_hpp

#include "GraphicsEngine.hpp"
#include "GameObject.hpp"

class Sun: public GameObject {
    public:
        Sun (GraphicsEngine* g);
       ~Sun ();
    
        virtual void update (State state) override;
    
    private:
    
        GraphicsObject* graphics;
    
};

#endif /* Sun_hpp */
