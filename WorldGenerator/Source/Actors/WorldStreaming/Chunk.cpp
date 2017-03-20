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

Chunk::Chunk (GraphicsEngine* g) {
    graphics = new GraphicsObject (
        new ModelGeometry("plane/plane"),
        new Material (ShaderCache::loadBasicShader("chunk"))
    );
    
    graphics->wireframe(false);
    
    g->add(graphics);
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
