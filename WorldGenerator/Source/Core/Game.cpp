//
//  Game.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Game.hpp"
#include "UIDelegate.hpp"
#include "Cursor.hpp"

#include "EngineTest.hpp"
#include <algorithm>

#define WIDTH 1920
#define HEIGHT 1080

Game::Game ():
    window   (WIDTH, HEIGHT),
    graphics (WIDTH, HEIGHT),
    physics  () {
    graphics.initPostProcessing();
}

Game::~Game () {}

void Game::boot () {
    InputManager::initialise(window.asGLFW());
    
    /* * * * * * * * * * * * * * * * *
     *  Objects
     * * * * * * * * * * * * * * * * */
    UIDelegate interface = UIDelegate(&graphics, &physics, this);
    Cursor     cursor    = Cursor(&graphics, &physics);
    
    EngineTest test   = EngineTest(&graphics, &physics);
    
    objects.push_back (&interface);
    objects.push_back (&cursor);
    objects.push_back (&test);
    
    while (window.isAlive()) {
        InputManager::update();
        physics.simulate(glfwGetTime());    // run physics simulation
        for (GameObject* o : objects)       // transfer data
            o-> update();
        graphics.render();                  // draw graphics scene
        window.swapBuffers();
    }
    
    glfwTerminate();
}

void Game::stop () {
    window.close();
}
