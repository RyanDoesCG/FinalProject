//
//  TriGeometry.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "TriGeometry.hpp"

using namespace glm;

TriGeometry::TriGeometry () {
    vertices = {
        Vertex(vec3(-0.5f,  0.0f, 0.0f), vec3(0, 0, 0), vec2(1.0f, 1.0f)), // Top Right
        Vertex(vec3( 0.0f,  0.5f, 0.0f), vec3(0, 0, 0), vec2(1.0,  0.0)),  // Bottom Right
        Vertex(vec3( 0.5f,  0.0f, 0.0f), vec3(0, 0, 0), vec2(0.0f, 1.0f)), // Top Left
    };
    
    indices  = {0, 1, 2};
    
    Geometry::setup();
}

TriGeometry::~TriGeometry () {}
