//
//  Chunk.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Chunk.hpp"
#include "ModelGeometry.hpp"
#include "ShaderCache.hpp"

Chunk::Chunk (GraphicsEngine* g, PhysicsEngine* p) {
    graphics = new GraphicsObject (
        new ModelGeometry("plane/plane"),
        new Material (ShaderCache::loadBasicShader("chunk"))
    );
    
    
    physics = new ChunkCollider (position);
    graphics->wireframe(false);
    
    g->add(graphics);
    p->addTo3D(physics);
}

Chunk::~Chunk () {       
    
}

void Chunk::update(State state) { graphics->position = position; graphics->colour = colour; }
void Chunk::recycleAt(glm::vec3 newPos) { position = newPos; }

/** should arrange them in a grid */
bool Chunk::operator<(const Chunk& that) const {
    return this->position.x + this->position.z <
           that .position.x + that .position.z;
}

bool Chunk::leftSideContact   () { return physics->touchingLeft(); }
bool Chunk::rightSideContact  () { return physics->touchingRight(); }
bool Chunk::topSideContact    () { return physics->touchingTop(); }
bool Chunk::bottomSideContact () { return physics->touchingBottom(); }
