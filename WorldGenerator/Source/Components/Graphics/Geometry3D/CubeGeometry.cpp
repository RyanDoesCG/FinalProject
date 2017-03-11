//
//  CubeGeometry.cpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "CubeGeometry.hpp"

using namespace glm;

CubeGeometry::CubeGeometry () {
    vertices = {
        Vertex(vec3(-0.5, -0.5,  0.5), vec3(0, 0, 0), vec2(0.0f, 0.0f)),
        Vertex(vec3( 0.5, -0.5,  0.5), vec3(0, 0, 0), vec2(0.0,  1.0)),
        Vertex(vec3( 0.5,  0.5,  0.5), vec3(0, 0, 0), vec2(1.0f, 0.0f)),
        Vertex(vec3(-0.5,  0.5,  0.5), vec3(0, 0, 0), vec2(1.0f, 1.0f)),
        
        Vertex(vec3(-0.5, -0.5, -0.5), vec3(0, 0, 0), vec2(0.0f, 0.0f)),
        Vertex(vec3( 0.5, -0.5, -0.5), vec3(0, 0, 0), vec2(0.0,  1.0)),
        Vertex(vec3( 0.5,  0.5, -0.5), vec3(0, 0, 0), vec2(1.0f, 0.0f)),
        Vertex(vec3(-0.5,  0.5, -0.5), vec3(0, 0, 0), vec2(1.0f, 1.0f))
    };
    
    indices  = {
        // front
        0, 1, 2, 2, 3, 0,
        // top
        1, 5, 6, 6, 2, 1,
        // back
        7, 6, 5, 5, 4, 7,
        // bottom
        4, 0, 3, 3, 7, 4,
        // left
        4, 5, 1, 1, 0, 4,
        // right
        3, 2, 6, 6, 7, 3,
    };
    
    Geometry::setup();
}

CubeGeometry::~CubeGeometry () {}
