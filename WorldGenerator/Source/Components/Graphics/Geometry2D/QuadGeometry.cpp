//
//  QuadGeometry.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "QuadGeometry.hpp"

using namespace glm;

QuadGeometry::QuadGeometry () {
    vertices = {
        Vertex(vec3(-1, -1, 0), vec3(0, 0, 1), vec2(1.0f, 1.0f)), // Top Right
        Vertex(vec3(-1,  1, 0), vec3(0, 0, 1), vec2(1.0,  0.0)),  // Bottom Right
        Vertex(vec3( 1,  1, 0), vec3(0, 0, 1), vec2(0.0f, 1.0f)), // Top Left
        Vertex(vec3( 1, -1, 0), vec3(0, 0, 1), vec2(0.0f, 0.0f))  // Bottom Left
    };
    
    indices  = {0, 1, 2, 0, 2, 3};
    
    Geometry::Geometry();
}

QuadGeometry::~QuadGeometry () {}
