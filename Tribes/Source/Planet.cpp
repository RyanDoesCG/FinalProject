/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Planet.hpp"

#include "../Headers/Engine/MeshComponent.hpp"
#include "../Headers/Engine/ShaderComponent.hpp"

Planet::Planet  () {
    
}

Planet::~Planet () {
    
}

void Planet::init() {
    std::vector<GLfloat> vertices = {
        // x      y      z      x      y      z      x      y      z
        -0.5f,  0.0f,  0.0f, 0.0f,  0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  // TRIANGLE 1
        -0.5f,  0.0f,  0.0f, 0.0f,  0.0f,  0.5f,  0.0f, -0.5f,  0.0f,  // TRIANGLE 2
        0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  // TRIANGLE 3
        0.0f, -0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  0.0f,  // TRIANGLE 4
        -0.5f,  0.0f,  0.0f, 0.0f,  0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  // TRIANGLE 5
        -0.5f,  0.0f,  0.0f, 0.0f, -0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  // TRIANGLE 6
        0.0f,  0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  0.5f,  0.0f,  0.0f,  // TRIANGLE 7
        0.0f,  0.0f, -0.5f,  0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  0.0f,  // TRIANGLE 8
    };
    
    addComponent(new ShaderComponent("BasicBlack"));
    addComponent(new MeshComponent(&vertices));
}

void Planet::update() {
    Actor::update();
}

void Planet::breakdownMesh () {
    
}

void Planet::normaliseMesh () {
    for (int i = 0; i < vertices.size(); i += 4) {
        float length = 1.0 + (float)(rand() % 10) / 100;
        std::cout << "length: " << length << std::endl;
        
        glm::vec3 a = glm::vec3(0.0, 0.0, 0.0); // center
        glm::vec3 b = glm::vec3(vertices.at(i + 0), vertices.at(i + 1), vertices.at(i + 2));
        
        // get the distance between a and b along the x and y axes
        GLfloat distX = b.x - a.x;
        GLfloat distY = b.y - a.y;
        GLfloat distZ = b.z - a.z;
        
        GLfloat a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
        
        // right now, sqrt(dx^2 + dy^2) = distance(a,b).
        // we want to modify them so that sqrt(dx^2 + dy^2) = the given length.
        distX = distX * length / a_b;
        distY = distY * length / a_b;
        distZ = distZ * length / a_b;
        
        vertices.at(i + 0) = (a.x + distX);
        vertices.at(i + 1) = (a.y + distY);
        vertices.at(i + 2) = (a.z + distZ);
    }
}
