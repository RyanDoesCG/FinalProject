/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/Biome.hpp"


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
        -0.5, 0, 0, -0.25, 0.25, 0, -0.25, 0, 0.25, -0.25, 0, 0.25, 0, 0, 0.5, 0, 0.25, 0.25,
        -0.25, 0.25, 0, -0.25, 0, 0.25, 0, 0.25, 0.25, 0, 0.5, 0, -0.25, 0.25, 0, 0, 0.25, 0.25,
        -0.5, 0, 0, -0.25, 0, 0.25, -0.25, -0.25, 0, -0.25, -0.25, 0, 0, -0.5, 0, 0, -0.25, 0.25,
        -0.25, 0, 0.25, -0.25, -0.25, 0, 0, -0.25, 0.25, 0, 0, 0.5, -0.25, 0, 0.25, 0, -0.25, 0.25,
        0.5, 0, 0, 0.25, 0.25, 0, 0.25, 0, 0.25, 0.25, 0, 0.25, 0, 0, 0.5, 0, 0.25, 0.25,
        0.25, 0.25, 0, 0.25, 0, 0.25, 0, 0.25, 0.25, 0, 0.5, 0, 0.25, 0.25, 0, 0, 0.25, 0.25,
        0, -0.5, 0, 0, -0.25, 0.25, 0.25, -0.25, 0, 0.25, -0.25, 0, 0.5, 0, 0, 0.25, 0, 0.25,
        0, -0.25, 0.25, 0.25, -0.25, 0, 0.25, 0, 0.25, 0, 0, 0.5, 0, -0.25, 0.25, 0.25, 0, 0.25,
        -0.5, 0, 0, -0.25, 0.25, 0, -0.25, 0, -0.25, -0.25, 0, -0.25, 0, 0, -0.5, 0, 0.25, -0.25,
        -0.25, 0.25, 0, -0.25, 0, -0.25, 0, 0.25, -0.25, 0, 0.5, 0, -0.25, 0.25, 0, 0, 0.25, -0.25,
        -0.5, 0, 0, -0.25, -0.25, 0, -0.25, 0, -0.25, -0.25, 0, -0.25, 0, 0, -0.5, 0, -0.25, -0.25,
        -0.25, -0.25, 0, -0.25, 0, -0.25, 0, -0.25, -0.25, 0, -0.5, 0, -0.25, -0.25, 0, 0, -0.25, -0.25,
        0, 0.5, 0, 0, 0.25, -0.25, 0.25, 0.25, 0, 0.25, 0.25, 0, 0.5, 0, 0, 0.25, 0, -0.25,
        0, 0.25, -0.25, 0.25, 0.25, 0, 0.25, 0, -0.25, 0, 0, -0.5, 0, 0.25, -0.25, 0.25, 0, -0.25,
        0, 0, -0.5, 0.25, 0, -0.25, 0, -0.25, -0.25, 0, -0.25, -0.25, 0, -0.5, 0, 0.25, -0.25, 0,
        0.25, 0, -0.25, 0, -0.25, -0.25, 0.25, -0.25, 0, 0.5, 0, 0, 0.25, 0, -0.25, 0.25, -0.25, 0,
    };

    breakdownMesh();
    breakdownMesh();
    
    normaliseMesh();

    // make water
    waterShader = (ShaderComponent*)addComponent(new ShaderComponent("water"));
    waterMesh   = (MeshComponent*)addComponent(new MeshComponent(&vertices));
    
    breakdownMesh();
    distortMesh();
    breakdownMesh();
    breakdownMesh();
    breakdownMesh();
    
    // make land graphics
    landLineShader = (ShaderComponent*)addComponent(new ShaderComponent("BasicBlack"));
    landFillShader = (ShaderComponent*)addComponent(new ShaderComponent("BasicWhite"));
    landMesh       = (MeshComponent*)addComponent(new MeshComponent(&vertices));

    
    spin = 0.00085;
    
    // move model to the left and shrink
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.4, 0, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5, 0.7, 0.7));
    
    initChildren();
    
    // TEMPORARY: send procedural colour to planet shader
    glm::vec4 color;
    
    color.r = (float)(rand() % 40) / 100;
    color.g = (float)(rand() % 40) / 100;
    color.b = (float)(rand() % 40) / 100;
    
    std::cout << "\n\nCOLOR: " << color.r << ", " << color.g << ", " << color.b << "\n\n";
    
    
    glUniform3f(glGetUniformLocation(landFillShader->getProgramID(), "proceduralColour"), color.r, color.g, color.b);
}

void Planet::update(GameState state) {
    // rotate
    modelMatrix = glm::rotate(modelMatrix, spin, glm::vec3(0.0f, 1.0f, 0.0f));

    // draw land outline
    landLineShader->update();
    glUniformMatrix4fv(glGetUniformLocation(landLineShader->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    landMesh->update();
    
    // draw land fill
    landFillShader->update();
    glUniformMatrix4fv(glGetUniformLocation(landFillShader->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    landMesh->update();

    // draw water
    waterShader->update();
    glUniformMatrix4fv(glGetUniformLocation(waterShader->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniform1f(glGetUniformLocation(waterShader->getProgramID(), "wave"), (float)(rand() % 2) / 1000);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    waterMesh->update();
    updateChildren(state);
}

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
        glm::vec3 d = getMidPoint (a, b);
        glm::vec3 e = getMidPoint (a, c);
        glm::vec3 f = getMidPoint (b, c);
        
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

//
//  O = N^2 | FIX THIS (semi-fixed with !normalised guard, now O= NlogN?)
//
//  Without (!normalised) condition guard:  4.8 seconds
//  With condition guard:                   0.8 seconds
//
//  int j = 0:                              0.909ms
//  int j = i:                              0.878ms
//
void Planet::normaliseMesh () {
    float start = glfwGetTime();
    int  noPoints = vertices.size() / 3;
    bool normalised[noPoints];
    
    for (int i = 0; i < noPoints; i ++)
        normalised[i] = false;
    
    for (int i = 0; i < vertices.size(); i += 3) {
        if (!normalised[i/3]) {
            float length = 0.9455;
        
            glm::vec3 a = glm::vec3(0.0, 0.0, 0.0);                                         // center
            glm::vec3 b = glm::vec3(vertices.at(i+0), vertices.at(i+1), vertices.at(i+2));  // point to normalise
        
            // get the distance between the center of the structure
            // and the point on the x, y and z axes.
            GLfloat distX = b.x - a.x;
            GLfloat distY = b.y - a.y;
            GLfloat distZ = b.z - a.z;
        
            // right now, sqrt(dx^2 + dy^2 + dz^2) == the distance between a and b
            GLfloat a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
        
            // we want to modify them so that sqrt(dx^2 + dy^2) = the given length.
            distX = distX * length / a_b;
            distY = distY * length / a_b;
            distZ = distZ * length / a_b;
        
            // apply new length to this vertex
            vertices.at(i + 0) = (a.x + distX);
            vertices.at(i + 1) = (a.y + distY);
            vertices.at(i + 2) = (a.z + distZ);
            normalised[i/3] = true;
        
            // check this vertex is repeated and apply the new length to that
            for (int j = i; j < vertices.size(); j+=3) {
                glm::vec3 c = glm::vec3(vertices.at(j + 0), vertices.at(j + 1), vertices.at(j + 2));
            
                if (b == c) {
                    vertices.at(j + 0) = (a.x + distX);
                    vertices.at(j + 1) = (a.y + distY);
                    vertices.at(j + 2) = (a.z + distZ);
                    normalised[j/3] = true;
                }
            }
        }
    }

    std::cout << "\nNormalisation Timer: " << glfwGetTime() - start << std::endl << std::endl;
}

void Planet::distortMesh () {
    float start = glfwGetTime();
    int  noPoints = vertices.size() / 3;
    bool normalised[noPoints];
    
    for (int i = 0; i < noPoints; i ++)
        normalised[i] = false;
    
    for (int i = 0; i < vertices.size(); i += 3) {
        if (!normalised[i/3]) {
            srand(i);
            float length = 0.9 + (float)(rand() % 10) / 100;
            
            glm::vec3 a = glm::vec3(0.0, 0.0, 0.0);                                         // center
            glm::vec3 b = glm::vec3(vertices.at(i+0), vertices.at(i+1), vertices.at(i+2));  // point to normalise
            
            // get the distance between the center of the structure
            // and the point on the x, y and z axes.
            GLfloat distX = b.x - a.x;
            GLfloat distY = b.y - a.y;
            GLfloat distZ = b.z - a.z;
            
            // right now, sqrt(dx^2 + dy^2 + dz^2) == the distance between a and b
            GLfloat a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
            
            // we want to modify them so that sqrt(dx^2 + dy^2) = the given length.
            distX = distX * length / a_b;
            distY = distY * length / a_b;
            distZ = distZ * length / a_b;
            
            // apply new length to this vertex
            vertices.at(i + 0) = (a.x + distX);
            vertices.at(i + 1) = (a.y + distY);
            vertices.at(i + 2) = (a.z + distZ);
            normalised[i/3] = true;
            
            // check this vertex is repeated and apply the new length to that
            for (int j = i; j < vertices.size(); j+=3) {
                glm::vec3 c = glm::vec3(vertices.at(j + 0), vertices.at(j + 1), vertices.at(j + 2));
                
                if (b == c) {
                    vertices.at(j + 0) = (a.x + distX);
                    vertices.at(j + 1) = (a.y + distY);
                    vertices.at(j + 2) = (a.z + distZ);
                    normalised[j/3] = true;
                }
            }
        }
    }
    
    std::cout << "\nDistortion Timer: " << glfwGetTime() - start << std::endl << std::endl;
}


void Planet::allocateBiomes() {
    biomeCount = 8;
    int pointsPerBiome = vertices.size() / biomeCount;
    
    for (int i = 0; i < biomeCount; i++) {
        std::vector<GLfloat> territory;
        //for (int j = 0; j < pointsPerBiome; j++) { territory.push_back(vertices.at(rand() % vertices.size())); }
        addChild(new Biome(&territory));
    }
}
