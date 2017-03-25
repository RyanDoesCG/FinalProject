//
//  Chunk.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Chunk.hpp"
#include "ModelCache.hpp"
#include "ShaderCache.hpp"

Chunk::Chunk (GraphicsEngine* g, PhysicsEngine* p) {
    graphics = new GraphicsObject (
        new ModelGeometry ("plane/plane"),
        new Material(ShaderCache::loadBasicShader("chunk"))
    );
    
    physics = new ChunkCollider (position, glm::vec2(2.0, 2.0));
    graphics->wireframe(false);
    
    g->add(graphics);
    p->addTo3D(physics);
}

Chunk::~Chunk () {       
    
}

void Chunk::update(State state) {
    
    if (physics->colliding) {
        colour = glm::vec4(0.45, 0.0, 0.0, 1.0);
    } else {
        colour = glm::vec4(0.0, 0.0, 0.45, 1.0);
    }
    
    // update graphics
    graphics->position = position; graphics->colour = colour;
}
void Chunk::recycleAt(glm::vec3 newPos) { position = newPos; }

bool Chunk::operator<(const Chunk& that) const
    { return this->distanceToCamera < that.distanceToCamera; }

bool Chunk::leftSideContact   () { return physics->touchingLeft(); }
bool Chunk::rightSideContact  () { return physics->touchingRight(); }
bool Chunk::topSideContact    () { return physics->touchingTop(); }
bool Chunk::bottomSideContact () { return physics->touchingBottom(); }
