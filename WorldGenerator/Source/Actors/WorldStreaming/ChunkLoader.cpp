//
//  ChunkLoader.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ChunkLoader.hpp"
#include "Random.hpp"

ChunkLoader::ChunkLoader (GraphicsEngine* g, PhysicsEngine* p) {
    
    // initialise variables
    chunkWidth        = 2.0f;
    maxWorldWidth     = 8;
    maxWorldDepth     = 8;
    baseY             = -2;
    graphics          = g;
    physics           = p;
    cam               = g->getSceneCamera ();
    
    // populate first chunks
    for (int x = 1; x < maxWorldWidth+1; x++) {
        for (int z = 1; z < maxWorldDepth+1; z++) {
            Chunk* c = new Chunk(g, p);
            c->position = glm::vec3(x * chunkWidth, baseY, z * chunkWidth);
            c->colour   = glm::vec4(unsignedRand(), unsignedRand(), unsignedRand(), 1.0);
            chunks.push_back(c);
        }
    }
    
    // populate first candidates
    for (int x = 0; x <= maxWorldWidth+1; x++) {
        if (x == 0 || x == maxWorldWidth+1) {
            for (int z = 0; z <= maxWorldDepth+1; z++) {
                Candidate* c = new Candidate(g);
                c->position = glm::vec3(x * chunkWidth, baseY, z * chunkWidth);
                candidates.push_back(c);
            }
        }
        
        else {
            Candidate* c1 = new Candidate(g);
            c1->position = glm::vec3(x * chunkWidth, baseY, 0 * chunkWidth);
            candidates.push_back(c1);
            
            Candidate* c2 = new Candidate(g);
            c2->position = glm::vec3(x * chunkWidth, baseY, (maxWorldWidth+1) * chunkWidth);
            candidates.push_back(c2);
        }
    }
    
    // calculate threshold
    for (Chunk* c : chunks) c->distanceToCamera = glm::length(c->position - cam->position);
    
    int sum = 0;
    for (Chunk* c : chunks) sum += c->distanceToCamera;
    sum /= chunks.size();
    sum -= 2;
    
    distanceThreshold = sum;
    
    // translate to centered
    for (Chunk* c     : chunks)     c->position -= glm::vec3((maxWorldWidth * 0.5) * chunkWidth, 0, (maxWorldDepth * 0.5) * chunkWidth);
    for (Candidate* c : candidates) c->position -= glm::vec3((maxWorldWidth * 0.5) * chunkWidth, 0, (maxWorldDepth * 0.5) * chunkWidth);
}

ChunkLoader::~ChunkLoader () {
    
}

void ChunkLoader::update(State state) {
    seekCandidates();
    fillCandidates();
    
    updateChunks(state);
    updateCandidates(state);
}

void ChunkLoader::seekCandidates() {
    //candidates.clear();
    
    // any chunk edge not touching another edge is a candidate
    for (Chunk* c : chunks) {
    /*
        if (!c->leftSideContact   ()) addCandidateAt(glm::vec3(c->position.x - chunkWidth, c->position.y, c->position.z));
        if (!c->rightSideContact  ()) addCandidateAt(glm::vec3(c->position.x + chunkWidth, c->position.y, c->position.z));
        if (!c->topSideContact    ()) addCandidateAt(glm::vec3(c->position.x, c->position.y, c->position.z + chunkWidth));
        if (!c->bottomSideContact ()) addCandidateAt(glm::vec3(c->position.x, c->position.y, c->position.z - chunkWidth));
    */
    }
    
}

void ChunkLoader::fillCandidates() {
    for (Chunk* c : chunks) c->distanceToCamera = glm::length(c->position - cam->position);
    
    // find any chunks violating the threshold
    for (Chunk* c : chunks)
        if (c->distanceToCamera > distanceThreshold && !candidates.empty()) {
            c->recycleAt(candidates.back()->position);
            candidates.pop_back();
        }
    
    // move them to candidate spaces
    
}

void ChunkLoader::addCandidateAt(glm::vec3 pos) {
    Candidate* c = new Candidate(graphics);
    c->position = pos;
    candidates.push_back(c);
}

void ChunkLoader::updateChunks(State state) {
    for (Chunk* c : chunks) c->update(state);
}

void ChunkLoader::updateCandidates(State state) {
    for (Candidate* c : candidates) c->update(state);
}
