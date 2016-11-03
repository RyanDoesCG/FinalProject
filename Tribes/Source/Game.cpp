/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Game.hpp"
#include "../Headers/GLFW/glfw3.h"

// Deterines window size/debug hud
#define BUILD_MODE DEVELOPMENT

Game::Game() {
    srand(generateSeed());
    
    // put engine stuff together
    if (BUILD_MODE == CINEMATIC) {
        windowWidth  = 1920;
        windowHeight = 1080;
    }
    
    else if (BUILD_MODE == DEVELOPMENT) {
        windowWidth  = 1200;
        windowHeight = 648;
    }
    
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
        
    backdrop = new Backdrop     (40000);
    planet   = new Planet       (TOUGHER, seed);
    hud      = new HUD          (this,  &delta);
    input    = new InputHandler (this);
    state    = RUNNING;
}

Game::~Game() {

}

/** 
 *  NEEDS MULTIPLE INPUT UPDATE FUNCTIONS THAT TAKE INTO ACCOUNT GAME STATE.
 *
 *  This will be really necessary in menus etc.
 */
void Game::begin() {
    glClearColor (0.075f, 0.075f, 0.075f, 0.0f);
    
    while (!glfwWindowShouldClose(window)) {
        input->update();
        
        if (state == RUNNING) {
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            backdrop->update();   // draw stars
            planet->update();     // draw planet
            hud->update();        // draw hud
            
            glfwSwapBuffers(window);
        }
        
        else {
            glfwWaitEvents();
        }
    }
}

void Game::end() {
    state = ENDED;
}

// toggle pause on and off
void Game::pause() {
    (state == RUNNING) ? state = PAUSED : state = RUNNING;
}

long Game::generateSeed() {
    srand(static_cast<unsigned int>(time(0)));
    seed = rand();
    std::cout << "World Seed: " << seed << std::endl <<std::endl;
    return seed;
}

int Game::initGLFW () {
    // start glfw Subsystem
    if (glfwInit() == GLFW_FALSE) return 1;
    
    glfwWindowHint   (GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL Version
    glfwWindowHint   (GLFW_CONTEXT_VERSION_MINOR, 2);                  // OpenGL Version
    glfwWindowHint   (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // OpenGL Profile
    glfwWindowHint   (GLFW_RESIZABLE, GL_TRUE);                        // Resizable Window
    glfwWindowHint   (GLFW_DOUBLEBUFFER, GL_TRUE);                     // Double Buffering
//  glfwWindowHint   (GLFW_MAXIMIZED, GL_TRUE);                        // Stick to corner
//  glfwWindowHint   (GLFW_SAMPLES, 4);                                // Multisampling
    glfwWindowHint   (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // macOS requires this
    glfwSwapInterval (1);                                              // enable VSYNC
    
    window = glfwCreateWindow(windowWidth, windowHeight, "Tribes - OpenGL", nullptr, nullptr);
    if (!window) return 1;
    
    glfwMakeContextCurrent(window);
    
    return 0;
}

int Game::initGLEW () {
    // initialise GLEW
    GLenum error = glewInit();
    if (error) return 1;
    
    // viewport
    glfwGetFramebufferSize (window, &windowWidth, &windowHeight);
    glViewport (0, 0, windowWidth, windowHeight);
    
    glEnable    (GL_DEPTH_TEST);    // Z BUFFERING
//  glEnable    (GL_MULTISAMPLE);   // MULTISAMPLING
    glEnable    (GL_BLEND);         // TEXT BLENDING
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}
