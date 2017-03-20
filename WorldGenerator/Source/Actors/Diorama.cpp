//
//  Diorama.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Diorama.hpp"
#include "PlaneGeometry.hpp"
#include "ModelGeometry.hpp"
#include "Rain.hpp"
#include "ShaderCache.hpp"

Diorama::Diorama (GraphicsEngine* g, PhysicsEngine* p) {
    heightmap = new HeightMap( "noise/test.jpg" );

    terrain = new GraphicsObject (
        new ModelGeometry ("plane/plane512"),
        new Material      (ShaderCache::loadBasicShader("plane_vertextextured"), heightmap->getID() )
    );
    
    water = new GraphicsObject (
        new ModelGeometry ("plane/plane512"),
        new Material      (ShaderCache::loadGeometryShader("plane_water"))
    );

    
    //rain = new Rain(g, p);
    
    //rain->position = glm::vec3(0, 8, -10);
    
    // Scale Fucks Placement
    // Geometry Shader???????????
    trees = new TreeSpawner (g, "trees/tree", heightmap, glm::vec4(0.05, 0.1, 0.0, 1.0), glm::vec3(0.02), 100);
    rocks = new RockSpawner (g, "trees/rock", heightmap, glm::vec4(0.21, 0.21, 0.21, 1.0), glm::vec3(0.02), 100);
    
    terrain->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    terrain->position = glm::vec3(10, -2, 10);
    terrain->scale    = glm::vec3(10, 10, 10);
    terrain->wireframe(true);
    
    water->colour   = glm::vec4(0.65, 0.7, 0.88, 0.25);
    //water->colour   = glm::vec4(1.0, 0.7, 0.7, 0.25);
    water->position = glm::vec3(10, -2, 10);
    water->scale    = glm::vec3(10, 10, 10);
    water->wireframe(false);
    
    g->add(terrain);
    g->add(water);
    
    mouse = InputManager::getMouseHandle();
    
    //terrain->rotation.x = 0.25;
    //water->rotation.x = 0.25;
    
    renderDistance = 10;
    seaLevel = 0;
    amp = 0.25;
    
    updateUniforms();
}

Diorama::~Diorama () {
    delete heightmap;
    delete terrain;
    delete water;
    delete trees;
    delete rocks;
}

void Diorama::setRenderDistance(GLfloat val) {
    renderDistance = val;
}

void Diorama::setAmplitude(GLfloat val) {
    amp = val;
}

void Diorama::setSeaLevel(GLfloat val) {
    seaLevel = val;
}

void Diorama::updateUniforms() {
    terrain->addUniform("renderDistance", renderDistance);
    terrain->addUniform("seaLevel", seaLevel);
    terrain->addUniform("amp", amp);
    
    water->addUniform("renderDistance", renderDistance);
    water->addUniform("seaLevel", seaLevel);
    water->addUniform("time", glfwGetTime());
    
    rocks->addUniform("renderDistance", renderDistance);
    rocks->addUniform("seaLevel", seaLevel);
    rocks->addUniform("amp", amp);
    
    trees->addUniform("renderDistance", renderDistance);
    trees->addUniform("seaLevel", seaLevel);
    trees->addUniform("amp", amp);
    
}

void Diorama::update(State state) {
    updateUniforms();
    
    std::cout << "  sea: " << seaLevel << std::endl;
    
    switch (state) {
        case MENU: {
            /*
            velocity.y += 0.0001;
            terrain->rotation += velocity;
            velocity *= 0.6;
            */
            break;
        }
            
        case VIEW: {
            /*
            velocity.y += 0.0001;
            if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
                velocity.y += 0.5 * mouse->getXoffset();
                terrain->scale += mouse->getYoffset() * 1.25;
                water->scale += mouse->getYoffset() * 1.25;
            }
            
            velocity.y += 0.01 * mouse->getScrollX();
            terrain->scale += mouse->getScrollY() * 0.25;
            water->scale += mouse->getScrollY() * 0.25;
            
            terrain->rotation += velocity;
            water->rotation += velocity;
            velocity *= 0.8;
            */
            break;
        }
    }
}
