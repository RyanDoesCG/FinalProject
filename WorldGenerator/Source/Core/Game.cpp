//
//  Game.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Game.hpp"
#include "ParticleEmitter.hpp"
#include "BasicLight.hpp"
#include "EngineTest.hpp"
#include "Butterfly.hpp"
#include "Diorama.hpp"
#include "Planet.hpp"
#include "BasicLight.hpp"

#include "ChunkLoader.hpp"

#include <algorithm>

#define WIDTH 1920 * 0.5
#define HEIGHT 1080 * 0.5

Game::Game ():
    window    (WIDTH, HEIGHT),
    graphics  (WIDTH, HEIGHT),
    physics   () {
        
    graphics.initPostProcessing();
}

Game::~Game () {}

void Game::showPlanet() {
    objects.clear();
    
    objects.push_back (interface);
    objects.push_back (cursor);
    objects.push_back (new Planet(&graphics));
}

void Game::showDiorama() {
    objects.clear();

    objects.push_back (interface);
    objects.push_back (cursor);
    objects.push_back (new BasicLight(&graphics));
    objects.push_back (diorama);
}

void Game::showTest () {
    objects.clear();
    
    objects.push_back (interface);
    objects.push_back (cursor);
    objects.push_back (new Butterfly(&graphics, &physics));
}

void Game::boot () {
    InputManager::initialise(window.asGLFW());
    
    interface = new UIDelegate(&graphics, &physics, this);
    cursor    = new Cursor(&graphics, &physics);
    objects.push_back (interface);
    objects.push_back (cursor);
    srand(time(0));
    
    /* * * * * * * * * * * * * * * * *
     *  Objects
     * * * * * * * * * * * * * * * * */
    ChunkLoader loader = ChunkLoader(&graphics);
    objects.push_back(&loader);
    
    state = VIEW;
    
    while (window.isAlive()) {
        InputManager::update();
        physics.simulate(glfwGetTime());    // run physics simulation
        for (GameObject* o : objects)       // transfer data
            o-> update(state);
        
        // script renderer
        switch (state) {
            case MENU: graphics.setEffect (GraphicsEngine::blur); break;
            case VIEW: graphics.setEffect (GraphicsEngine::fade); break;
        }
        
        graphics.render(state);                  // draw graphics scene
        window.swapBuffers();
    }
    
    glfwTerminate();
}

void Game::stop () {
    window.close();
}
