//
//  Game.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Game.hpp"
#include "ParticleEmitter.hpp"
#include "Sun.hpp"
#include "EngineTest.hpp"
#include "Butterfly.hpp"
#include "Diorama.hpp"
#include "Planet.hpp"

#include "ChunkLoader.hpp"

#include <algorithm>

#define WIDTH 1920
#define HEIGHT 1080

Game::Game ():
    window    (WIDTH, HEIGHT),
    graphics  (WIDTH, HEIGHT),
    physics   () {
        
    srand(time(0));
    graphics.initPostProcessing ();
    graphics.initTextRendering  ();
}

Game::~Game () {}

void Game::showPlanet() {
    planet->addToWorld();
    diorama->removeFromWorld();
}

void Game::showDiorama() {
    diorama->addToWorld();
    planet->removeFromWorld();
}

void Game::showTest () {
    objects.clear();
    
    objects.push_back (interface);
    objects.push_back (cursor);
    objects.push_back (new Butterfly(&graphics, &physics));
}

void Game::boot () {
    
    
    InputManager::initialise(window.asGLFW());
    
    diorama   = new Diorama(&graphics, &physics);
    planet    = new Planet(&graphics);
    
    interface = new UIDelegate(&graphics, &physics, this);
    cursor    = new Cursor(&graphics, &physics);
    
    
    objects.push_back (diorama);
    objects.push_back (planet);
    objects.push_back (interface);
    objects.push_back (cursor);
    
     
    /* * * * * * * * * * * * * * * * *
     *  Objects
     * * * * * * * * * * * * * * * * */
   // ChunkLoader loader = ChunkLoader(&graphics, &physics);
   // objects.push_back(&loader);
    
    showDiorama ();
    
   // EngineTest cube = EngineTest(&graphics, &physics);
   // objects.push_back(&cube);
    
    state = MENU;
    
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
        
        //if (input.getKeyboardHandle()->isKeyDown(GLFW_KEY_R)) graphics.setEffect (GraphicsEngine::none);
        //if (input.getKeyboardHandle()->isKeyDown(GLFW_KEY_T)) graphics.setEffect (GraphicsEngine::blur);
        //if (input.getKeyboardHandle()->isKeyDown(GLFW_KEY_Y)) graphics.setEffect (GraphicsEngine::fade);

        
        graphics.render(state);                  // draw graphics scene
        window.swapBuffers();
    }
    
    glfwTerminate();
}

void Game::stop () {
    window.close();
}
