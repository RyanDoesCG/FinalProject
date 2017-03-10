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
        Vertex(vec3(-0.5f,  -0.5f, 0.0f), vec3(0, 0, 0), vec2(1.0f, 1.0f)),
        Vertex(vec3(-0.5f,  0.5f, 0.0f), vec3(0, 0, 0), vec2(1.0,  0.0)),
        Vertex(vec3( 0.5f,  -0.5f, 0.0f), vec3(0, 0, 0), vec2(0.0f, 1.0f)),
        Vertex(vec3( 0.5f,  0.5f, 0.0f), vec3(0, 0, 0), vec2(0.0f, 1.0f))
    };
    
    indices  = {0, 1, 2, 2, 1, 3};
    
    Geometry::setup();
}

QuadGeometry::~QuadGeometry () {}
