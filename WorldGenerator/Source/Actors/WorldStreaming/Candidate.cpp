//
//  Candidate.cpp
//  WorldGenerator
//
//  Created by user on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Candidate.hpp"
#include "ModelCache.hpp"
#include "ShaderCache.hpp"

Candidate::Candidate (GraphicsEngine* g) {
    /*
    graphics = new GraphicsObject (
        ModelCache::loadModelGeometry("plane/plane"),
        new Material (ShaderCache::loadBasicShader("object"))
    );
     */
    
    colour = glm::vec4(0.21, 0.21, 0.21, 1.0);
    //graphics->wireframe(true);
    //g->add(graphics);
}

Candidate::~Candidate () {

}

void Candidate::update(State state) { /*graphics->position = position; graphics->colour = colour;*/ }
void Candidate::recycleAt(glm::vec3 newPos) { position = newPos; }

bool Candidate::operator < (const Candidate& that) const
    { return this->distanceToCamera < that.distanceToCamera; }
