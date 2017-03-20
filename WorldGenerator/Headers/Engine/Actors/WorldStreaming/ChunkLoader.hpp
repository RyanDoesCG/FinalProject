//
//  ChunkLoader.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ChunkLoader_hpp
#define ChunkLoader_hpp

#include "GameObject.hpp"

class ChunkLoader: public GameObject {
    public:
        ChunkLoader ();
       ~ChunkLoader ();
    
        virtual void update (State state) override;
};

#endif /* ChunkLoader_hpp */
