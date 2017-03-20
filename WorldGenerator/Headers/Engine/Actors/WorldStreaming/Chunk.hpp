//
//  Chunk.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Chunk_hpp
#define Chunk_hpp

#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"

class Chunk: public GameObject {
    public:
        Chunk (GraphicsEngine* g);
       ~Chunk ();
    
        void update (State state) override;
        void recycleAt (glm::vec3 newPos);
    
        bool operator<(const Chunk& rhs) const;
    
    private:
        GraphicsObject* graphics;
    
        float distanceToCamera;
    
};

#endif /* Chunk_hpp */