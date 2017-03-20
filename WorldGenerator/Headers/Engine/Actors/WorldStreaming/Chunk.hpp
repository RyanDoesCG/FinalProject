//
//  Chunk.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Chunk_hpp
#define Chunk_hpp

class Chunk: public GameObject {
    public:
        Chunk ();
       ~Chunk ();
    
        virtual void update (State state) override;
    
    private:
    
};

#endif /* Chunk_hpp */
