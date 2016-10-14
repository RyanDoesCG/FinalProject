/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGraphics.cpp
 *  Tribes
 *
 *  Created by user on 12/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/PlanetGraphics.hpp"
#include "../Headers/Engine/MathsToolkit.hpp"
#include <vector>

PlanetGraphics::PlanetGraphics  () {

    // octohedron
    std::vector<GLfloat> vertices = {
        // 1
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.75f, 0.0f,
        0.0f, 0.0f, 0.5f,
        
        // 2
        -0.5, 0.0f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.0f, -0.75, 0.0f,
        
        // 3
        0.5f, 0.0f, 0.0f,
        0.0f, 0.75f, 0.0f,
        0.0f, 0.0f, 0.5f,
        
        // 4
        0.0f, -0.75f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.5f, 0.00f, 0.0f,
        
        // 5
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.75f, 0.0f,
        0.0f, 0.0f, -0.5f,
        
        // 6
        -0.5, 0.0f, 0.0f,
        0.0f, -0.75, 0.0f,
        0.0f, 0.0f, -0.5f,
        
        
        // 7
        0.0f, 0.75f, 0.0f,
        0.0f, 0.0f, -0.5f,
        0.5f, 0.0f, 0.0f,
        
        // 8
        0.0f, 0.0f, -0.5f,
        0.5f, 0.00f, 0.0f,
        0.0f, -0.75f, 0.0f,    
    };
    
    MathsToolkit::parseOctohedron(&vertices);
    //MathsToolkit::normalizeOctohedron(&vertices);

    objectShaders.push_back(new Shader("BasicBlack"));
    objectTexture = new Texture("water");
    objectMesh = new Mesh(&vertices);

}

PlanetGraphics::~PlanetGraphics () {

}


//    std::vector<GLfloat> vertices = {
//        /*pos*/  0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 0.0f, 0.0f, /*tc*/ 1.0f, 1.0f,
//        /*pos*/  0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 1.0f, 0.0f, /*tc*/ 1.0f, 0.0f,
//        /*pos*/ -0.5f,-0.5f, 0.0f, /*col*/ 0.0f, 0.0f, 1.0f, /*tc*/ 0.0f, 0.0f,
//        /*pos*/ -0.5f, 0.5f, 0.0f, /*col*/ 1.0f, 1.0f, 0.0f, /*tc*/ 0.0f, 1.0f
//     };

//    std::vector<GLuint> indices = {
//        0, 1, 2,
//        0, 3, 2
//    };

/*
 // cube
 std::vector<GLfloat> vertices = {
 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
 
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
 -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 
 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
 
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
 -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
 };
 */
