//
//  Planet.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Planet.hpp"
#include "PlaneGeometry.hpp"
#include "ModelGeometry.hpp"
#include "ShaderCache.hpp"

#include "Forrest.hpp"
#include "Arctic.hpp"
#include "Volcanic.hpp"
#include "Alien.hpp"
#include "Arctic.hpp"
#include "Desert.hpp"

void Planet::pickBiome() {
    switch (rand() % 5) {
        case 0: biome = new Forrest(); break;
        case 1: biome = new Desert(); break;
        case 2: biome = new Volcanic(); break;
        case 3: biome = new Alien(); break;
        case 4: biome = new Arctic(); break;
    }
    
    terrain->colour   = biome->getPrimaryColour();
    water->colour   = biome->getUnderwaterColour();
    
    //delete trees;
    //delete rocks;
    
    //trees = new TreeSpawner (graphEng, biome->getTreePath(), heightmap, biome->getTreeColour(), glm::vec3(0.02), 100);
    //rocks = new RockSpawner (graphEng, biome->getRockPath(), heightmap, biome->getRockColour(), glm::vec3(0.02), 100);
    
    
}

Planet::Planet (GraphicsEngine* g, PhysicsEngine* p) {
    heightmap = new HeightMap("sphereMaps/" + std::to_string(rand() % 100) + ".jpg");
    
    terrain = new GraphicsObject(
        new ModelGeometry ("sphere/uvsphere"),
        new Material      (ShaderCache::loadGeometryShader("planet"), heightmap->getID())
    );
    
    water = new GraphicsObject (
        new ModelGeometry ("sphere/sphere"),
        new Material      (ShaderCache::loadBasicShader("object_lit"))
    );
    
    //terrain->colour   = glm::vec4(0.31, 0.31, 0.31, 1);
    terrain->position = glm::vec3(10, 0, -20);
    terrain->scale    = glm::vec3(10, 10, 10);
    terrain->wireframe(false);
    
    //water->colour   = glm::vec4(0.65, 0.7, 0.88, 0.25);
    water->colour   = glm::vec4(1.0, 0.7, 0.7, 1);
    water->position = glm::vec3(10, 0, -20);
    water->scale    = glm::vec3(10.5, 10.5, 10.5);
    water->wireframe(false);
    water->shouldntCull(true);
    
    stars = new Stars(g, p);
    
    g->add(terrain);
    g->add(water);
    
    graphEng = g;
    
    mouse = InputManager::getMouseHandle();
    keys  = InputManager::getKeyboardHandle();
    
    terrain->rotation.x = 0.25;
    

    amp = 0.25;
    mode = 0.0;
    updateUniforms();
}

Planet::~Planet () {}

void Planet::removeFromWorld () {
    terrain->shouldDraw(false);
    water->shouldDraw(false);
}

void Planet::addToWorld () {
    terrain->shouldDraw(true);
    water->shouldDraw(true);
}

void Planet::updateUniforms() {
    terrain->addUniform1f("smoothing", 0.001);
    terrain->addUniform1f("amp", amp);
    terrain->addUniform1f("mode", mode);
    
    water->addUniform1f("time", glfwGetTime());
}

void Planet::changeHeightMap() {
    heightmap = new HeightMap("planeMaps/" + std::to_string(rand() % 100) + ".jpg");
    terrain->material->setTexture(heightmap->getID());
    
    mode = fmod((mode + 1), 3);
    
    pickBiome();
}

void Planet::update(State state) {
    updateUniforms();
    
    switch (state) {
        case MENU: {
        
            restx = 10;
            resty = 0;
            if (terrain->position.x > restx) { terrain->position.x -= (restx - terrain->position.x) * -0.05; }
            if (water->position.x > restx) { water->position.x -= (restx - water->position.x) * -0.05; }
            if (terrain->position.y > resty) { terrain->position.y -= (resty - terrain->position.y) * -0.05; }
            if (water->position.y > resty) { water->position.y -= (resty - water->position.y) * -0.05; }
            
            
            velocity.y += 0.001;
            terrain->rotation += velocity;
            velocity *= 0.8;
            
            break;
        }
            
        case VIEW: {
            restx = 18;
            resty = 0;
            if (terrain->position.x < restx) { terrain->position.x += (restx - terrain->position.x) * 0.05; }
            if (water->position.x   < restx) { water->position.x   += (restx - water->position.x) * 0.05; }
            if (terrain->position.y < restx) { terrain->position.y += (resty - terrain->position.y) * 0.05; }
            if (water->position.y   < restx) { water->position.y   += (resty - water->position.y) * 0.05; }
            
            
            velocity.y += 0.001;
            if (mouse->leftButtonDown() || mouse->rightButtonDown()) {
                //velocity.y += 0.5 * mouse->getXoffset();
                //terrain->scale += mouse->getYoffset() * 1.25;
                //water->scale += mouse->getYoffset() * 1.25;
            } else {
                velocity.y += 0.01 * mouse->getScrollX();
                terrain->scale += mouse->getScrollY() * 0.25;
                water->scale += mouse->getScrollY() * 0.25;
            }
            
            terrain->rotation += velocity;
            velocity *= 0.8;
            
            //std::cout << "scl: " << terrain->scale.x << std::endl;
            
            if (terrain->scale.x > maxScale) {terrain->scale = glm::vec3(maxScale); water->scale = glm::vec3(maxScale + 0.5); }
            if (terrain->scale.x < minScale) {terrain->scale = glm::vec3(minScale); water->scale = glm::vec3(minScale + 0.5); }
            
            if (keys->isKeyDown(GLFW_KEY_X)) { changeHeightMap(); }
            
            break;
        }
    }
}
