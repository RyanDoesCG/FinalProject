//
//  BasicLight.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef BasicLight_hpp
#define BasicLight_hpp

#include "GraphicsEngine.hpp"
#include "GameObject.hpp"

class BasicLight: public GameObject {
    public:
        BasicLight (GraphicsEngine* g);
       ~BasicLight ();
    
        virtual void update (State state) override;
    
    private:
    
        GraphicsObject* graphics;
    
};

#endif /* BasicLight_hpp */
