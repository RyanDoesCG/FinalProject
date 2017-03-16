//
//  Rain.hpp
//  WorldGenerator
//
//  Created by user on 15/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Rain_hpp
#define Rain_hpp

#include "ParticleEmitter.hpp"

class Rain : public ParticleEmitter {
    public:
        Rain (GraphicsEngine* graph, PhysicsEngine* phys);
       ~Rain ();
};

#endif /* Rain_hpp */
