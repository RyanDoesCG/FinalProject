//
//  Game.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "Game.hpp"
#include "UIBox.hpp"
#include "Cursor.hpp"
#include <algorithm>

#define WIDTH 600
#define HEIGHT 400

Game::Game (): window(WIDTH, HEIGHT), graphics (WIDTH, HEIGHT), physics() {

}

Game::~Game () {
    
}

void updateObjects (GameObject* o) { o->update(); }

void Game::boot () {
    glClearColor (0.93f, 0.90f, 0.83f, 1.0f);
    InputManager::initialise(window.asGLFW());
    
    std::vector<GameObject*> objects;
    
    /* * * * * * * * * * * * * * * * *
     *  Objects
     * * * * * * * * * * * * * * * * */
    Cursor     cursor = Cursor(&graphics, &physics);
    UIBox      box    = UIBox(&graphics, &physics);

    objects.push_back(&cursor);
    objects.push_back(&box);
    
    while (window.isAlive()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        InputManager::update();
        
        physics.simulate(glfwGetTime());
        for_each(objects.begin(), objects.end(), updateObjects);
        graphics.render();

        window.swapBuffers();
        
    }
    
    glfwTerminate();
}
