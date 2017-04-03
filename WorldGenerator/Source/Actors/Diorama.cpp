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
#include "CubeGeometry.hpp"
#include "Rain.hpp"
#include "Stars.hpp"
#include "ShaderCache.hpp"

Diorama::Diorama (GraphicsEngine* g, PhysicsEngine* p) {
    //heightmap = new HeightMap( "noise_generation/output_" + std::to_string(rand() % 99) + ".jpg" );
    //heightmap = new HeightMap( "noise/layerTest.jpg");
    heightmap = new HeightMap("heightMapMakerPro/" + std::to_string(rand() % 100) + ".jpg");


    terrain = new GraphicsObject (
        new ModelGeometry ("plane/plane512"),
    //  new Material      (ShaderCache::loadBasicShader("plane_vertextextured"), heightmap->getID() )
       new Material      (ShaderCache::loadGeometryShader("plane_vertextextured_recalc"), heightmap->getID() )
    );
    
    water = new GraphicsObject (
        new ModelGeometry ("plane/plane512"),
        new Material      (ShaderCache::loadGeometryShader("plane_water"))
    );
    
    base = new GraphicsObject (
        new CubeGeometry (),
        new Material (ShaderCache::loadBasicShader("object"))
    );
    
    stars = new Stars (g, p);
    
    //rain = new Rain(g, p);
    
    // rain->position = glm::vec3(0, 8, -10);
    
    // Scale Fucks Placement
    // Geometry Shader???????????
    trees = new TreeSpawner (g, biome->getTreePath(), heightmap, glm::vec4(0.05, 0.5, 0.05, 1.0), glm::vec3(0.02), 100);
    rocks = new RockSpawner (g, biome->getRockPath(), heightmap, glm::vec4(0.21, 0.21, 0.21, 1.0), glm::vec3(0.02), 100);
    
    terrain->colour   = biome->getPrimaryColour();
    terrain->position = glm::vec3(10, -2, 10);
    terrain->scale    = glm::vec3(10, 10, 10);
    terrain->wireframe(false);
    
    water->colour   = biome->getUnderwaterColour();
    //water->colour   = glm::vec4(1.0, 0.7, 0.7, 0.25);
    water->position = glm::vec3(10, -2, 10);
    water->scale    = glm::vec3(30, 10, 30);
    water->wireframe(false);
    
    base->colour = glm::vec4(0.0, 0.0, 0.0, 1.0);
    base->position = glm::vec3(10, -2.5, 10);
    base->scale   = glm::vec3(20, 2, 20);
    
    graphEng = g;
    
    g->add(terrain);
    g->add(water);
   // g->add(base);
    
    mouse = InputManager::getMouseHandle();
    keys = InputManager::getKeyboardHandle();
    
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

void Diorama::changeHeightMap() {
    heightmap = new HeightMap("heightMapMakerPro/" + std::to_string(rand() % 100) + ".jpg");
    terrain->material->setTexture(heightmap->getID());
    rocks->setHeightMap(heightmap->getID());
    trees->setHeightMap(heightmap->getID());
}

void Diorama::updateUniforms() {
    // SMOOTHING VALUE?
    terrain->addUniform1f("renderDistance", renderDistance);
    terrain->addUniform1f("seaLevel", seaLevel);
    terrain->addUniform1f("smoothing", 0.001);
    terrain->addUniform1f("amp", amp);
    
    water->addUniform1f("renderDistance", renderDistance);
    water->addUniform1f("seaLevel", seaLevel);
    water->addUniform1f("time", glfwGetTime());
    
    
    rocks->addUniform1f("renderDistance", renderDistance);
    rocks->addUniform1f("seaLevel", seaLevel);
    rocks->addUniform1f("amp", amp);
    
    trees->addUniform1f("renderDistance", renderDistance);
    trees->addUniform1f("seaLevel", seaLevel);
    trees->addUniform1f("amp", amp);
    
}

void Diorama::removeFromWorld () {
    terrain->shouldDraw(false);
    water->shouldDraw(false);
    stars->shouldDraw(false);
    trees->shouldDraw(false);
    rocks->shouldDraw(false);
}

void Diorama::addToWorld () {
    terrain->shouldDraw(true);
    water->shouldDraw(true);
    stars->shouldDraw(true);
    trees->shouldDraw(true);
    rocks->shouldDraw(true);
}

void Diorama::update(State state) {
    updateUniforms();
    
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
            
            if (keys->isKeyDown(GLFW_KEY_X)) { changeHeightMap(); }
            
            break;
        }
    }
}
