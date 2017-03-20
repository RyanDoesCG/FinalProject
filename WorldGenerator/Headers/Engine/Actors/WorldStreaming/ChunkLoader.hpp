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
#include "Candidate.hpp"
#include "Chunk.hpp"
#include <vector>

class ChunkLoader: public GameObject {
    public:
        ChunkLoader (GraphicsEngine* g);
       ~ChunkLoader ();
    
        void update (State state) override;
    private:
    
        // main stages
        void seekCandidates ();
        void fillCandidates ();
    
        // housekeeping
        void updateChunks     (State state);
        void updateCandidates (State state);
    
        /** 
         *  chunks cannot leave world boundries,
         *  candidates can.
         */
        std::vector<Chunk*> chunks;
        std::vector<Candidate*> candidates;
    
        float distanceThreshold;            // distance at which to recycle
        float chunkWidth;                   // size of one chunk on one axis (chunks are square)
        unsigned int maxWorldWidth;
        unsigned int maxWorldDepth;
        float baseY;
    
        Camera* cam;                        // the camera for retriving its position
};

#endif /* ChunkLoader_hpp */
