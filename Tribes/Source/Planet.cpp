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

glm::vec3 getMidPoint (glm::vec3 a, glm::vec3 b) {
    return glm::vec3(
        (a.x + b.x) / 2,
        (a.y + b.y) / 2,
        (a.z + b.z) / 2
    );
}

Planet::Planet  () {

}

Planet::~Planet () {
    
}

void Planet::init() {
    
    vertices = {
      // x      y      z     x      y      z      x      y      z
        -0.5f,  0.0f,  0.0f, 0.0f,  0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  // TRIANGLE 1
        -0.5f,  0.0f,  0.0f, 0.0f,  0.0f,  0.5f,  0.0f, -0.5f,  0.0f,  // TRIANGLE 2
         0.5f,  0.0f,  0.0f, 0.0f,  0.5f,  0.0f,  0.0f,  0.0f,  0.5f,  // TRIANGLE 3
         0.0f, -0.5f,  0.0f, 0.0f,  0.0f,  0.5f,  0.5f,  0.0f,  0.0f,  // TRIANGLE 4
        -0.5f,  0.0f,  0.0f, 0.0f,  0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  // TRIANGLE 5
        -0.5f,  0.0f,  0.0f, 0.0f, -0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  // TRIANGLE 6
         0.0f,  0.5f,  0.0f, 0.0f,  0.0f, -0.5f,  0.5f,  0.0f,  0.0f,  // TRIANGLE 7
         0.0f,  0.0f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f, -0.5f,  0.0f,  // TRIANGLE 8
    };

    breakdownMesh();
    breakdownMesh();
    breakdownMesh();
    breakdownMesh();
    normaliseMesh();
    
    addComponent(new ShaderComponent("BasicBlack"));
    addComponent(new ShaderComponent("BasicWhite"));
    addComponent(new MeshComponent(&vertices));
    
    modelMatrix = glm::rotate (modelMatrix, (GLfloat)0.2, glm::vec3(1.0f, 0.0f, 0.0f)); // kick/tilt back
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.4, 0, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4, 0.6, 0.6));
    
    // C++ / OpenGL Engineers: "How can we make the code look reeaalllyyy gross?"
    glUniformMatrix4fv (glGetUniformLocation(dynamic_cast<ShaderComponent*>(components.at(0))->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv (glGetUniformLocation(dynamic_cast<ShaderComponent*>(components.at(1))->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

}

void Planet::update() {
    dynamic_cast<ShaderComponent*>(components.at(0))->update();
    modelMatrix = glm::rotate(modelMatrix, (GLfloat)0.002, glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(dynamic_cast<ShaderComponent*>(components.at(0))->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    components.at(2)->update();
    
    dynamic_cast<ShaderComponent*>(components.at(1))->update();
    modelMatrix = glm::rotate(modelMatrix, (GLfloat)0.002, glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(dynamic_cast<ShaderComponent*>(components.at(1))->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    components.at(2)->update();
    
        // Actor::update();
}

//
//  The day i get this right i will jump for joy and kiss the nearest person
//
void Planet::breakdownMesh () {
    std::vector<GLfloat> newVerts = {};
    int i;
    
    // for every one triangle in the skeleton mesh, four triangles are generated
    // by this funciton and assigned to a new std::vector that is then copied to
    // the old vertices std::vector
    for (i = 0; i < vertices.size(); i += 9) {
        glm::vec3 a = glm::vec3(vertices.at(i+0), vertices.at(i+1), vertices.at(i+2));
        glm::vec3 b = glm::vec3(vertices.at(i+3), vertices.at(i+4), vertices.at(i+5));
        glm::vec3 c = glm::vec3(vertices.at(i+6), vertices.at(i+7), vertices.at(i+8));
        
        glm::vec3 d = getMidPoint (
            a,
            b
        );
        
        glm::vec3 e = getMidPoint (
            a,
            c
        );
        
        glm::vec3 f = getMidPoint (
            b,
            c
        );
        
        // insert in clockwise order
        newVerts.push_back(a.x); newVerts.push_back(a.y); newVerts.push_back(a.z);
        newVerts.push_back(d.x); newVerts.push_back(d.y); newVerts.push_back(d.z);
        newVerts.push_back(e.x); newVerts.push_back(e.y); newVerts.push_back(e.z);
        
        newVerts.push_back(e.x); newVerts.push_back(e.y); newVerts.push_back(e.z);
        newVerts.push_back(c.x); newVerts.push_back(c.y); newVerts.push_back(c.z);
        newVerts.push_back(f.x); newVerts.push_back(f.y); newVerts.push_back(f.z);
        
        newVerts.push_back(d.x); newVerts.push_back(d.y); newVerts.push_back(d.z);
        newVerts.push_back(e.x); newVerts.push_back(e.y); newVerts.push_back(e.z);
        newVerts.push_back(f.x); newVerts.push_back(f.y); newVerts.push_back(f.z);
        
        newVerts.push_back(b.x); newVerts.push_back(b.y); newVerts.push_back(b.z);
        newVerts.push_back(d.x); newVerts.push_back(d.y); newVerts.push_back(d.z);
        newVerts.push_back(f.x); newVerts.push_back(f.y); newVerts.push_back(f.z);

    }
    
    vertices.clear();
    vertices.insert(vertices.begin(), newVerts.begin(), newVerts.end());

}

void Planet::normaliseMesh () {
    for (int i = 0; i < vertices.size(); i += 3) {
        float length = 1.0 + (float)(rand() % 10) / 100;
        
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
        
        // apply new length to this vector and any that share its values
        vertices.at(i + 0) = (a.x + distX);
        vertices.at(i + 1) = (a.y + distY);
        vertices.at(i + 2) = (a.z + distZ);
        
        for (int j = 0; j < vertices.size(); j+=3) {
            glm::vec3 c = glm::vec3(vertices.at(j + 0), vertices.at(j + 1), vertices.at(j + 2));
            
            if (b == c) {
                vertices.at(j + 0) = (a.x + distX);
                vertices.at(j + 1) = (a.y + distY);
                vertices.at(j + 2) = (a.z + distZ);
            }
        }
    }
}
