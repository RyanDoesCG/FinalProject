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
#include "PhysicsEngine.hpp"
#include "ChunkCollider.hpp"

#include "GameObject.hpp"

class Chunk: public GameObject {
    public:
        Chunk (GraphicsEngine* g, PhysicsEngine* p);
       ~Chunk ();
    
        void update (State state) override;
        void recycleAt (glm::vec3 newPos);
    
        float distanceToCamera;
    
        bool leftSideContact   ();
        bool rightSideContact  ();
        bool topSideContact    ();
        bool bottomSideContact ();
    
        bool operator<(const Chunk& rhs) const;
    
    private:
        GraphicsObject* graphics;
        ChunkCollider*  physics;
    
};

#endif /* Chunk_hpp */
