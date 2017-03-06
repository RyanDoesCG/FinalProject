//
//  Game.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Game.hpp"

Game::Game (): window(1920, 1080) {
    graphics = GraphicsEngine ();
    physics  = PhysicsEngine  ();
    
    
}

Game::~Game () {
    
}

void Game::boot () {
    glClearColor (0.93f, 0.90f, 0.83f, 1.0f);
    InputManager::initialise(window.asGLFW());

    while (window.isAlive()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        InputManager::update();

        window.swapBuffers();
        
    }
    
    glfwTerminate();
}
