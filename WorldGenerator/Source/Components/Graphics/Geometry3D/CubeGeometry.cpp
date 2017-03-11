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
        Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3( 0.0f,  0.0f, -1.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f, -0.5f), vec3( 0.0f,  0.0f, -1.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f,  0.5f, -0.5f), vec3( 0.0f,  0.0f, -1.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f,  0.5f, -0.5f), vec3( 0.0f,  0.0f, -1.0f), vec2(0.0, 0.0)),
                                                  
        Vertex(vec3(-0.5f, -0.5f,  0.5f), vec3( 0.0f,  0.0f,  1.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f,  0.5f), vec3( 0.0f,  0.0f,  1.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f,  0.5f,  0.5f), vec3( 0.0f,  0.0f,  1.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f,  0.5f,  0.5f), vec3( 0.0f,  0.0f,  1.0f), vec2(0.0, 0.0)),
                                                                                            
        Vertex(vec3(-0.5f,  0.5f,  0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f,  0.5f, -0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f, -0.5f,  0.5f), vec3(-1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
                                                                                                                                      
        Vertex(vec3( 0.5f,  0.5f,  0.5f), vec3( 1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f,  0.5f, -0.5f), vec3( 1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f, -0.5f), vec3( 1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f,  0.5f), vec3( 1.0f,  0.0f,  0.0f), vec2(0.0, 0.0)),
                                                                                                                                                                                
        Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3( 0.0f, -1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f, -0.5f), vec3( 0.0f, -1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f, -0.5f,  0.5f), vec3( 0.0f, -1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f, -0.5f,  0.5f), vec3( 0.0f, -1.0f,  0.0f), vec2(0.0, 0.0)),
               
        Vertex(vec3(-0.5f,  0.5f, -0.5f), vec3( 0.0f,  1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f,  0.5f, -0.5f), vec3( 0.0f,  1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3( 0.5f,  0.5f,  0.5f), vec3( 0.0f,  1.0f,  0.0f), vec2(0.0, 0.0)),
        Vertex(vec3(-0.5f,  0.5f,  0.5f), vec3( 0.0f,  1.0f,  0.0f), vec2(0.0, 0.0))
    };
    
    indices  = {
        0,   1,  2,  2,  3,  0,
        4,   5,  6,  6,  7,  4,
        8,   9, 10, 10, 11,  8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 12, 22, 22, 23, 20
    };
    
    
    Geometry::setup();
}

CubeGeometry::~CubeGeometry () {}
