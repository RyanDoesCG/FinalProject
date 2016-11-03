/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Game.hpp"
#include "../Headers/Engine/Player.hpp"

// Deterines window size/debug hud
#define BUILD_MODE CINEMATIC

Game::Game() {
    srand(generateSeed());
    
    // decide what window to build
    if (BUILD_MODE == CINEMATIC) {
        windowWidth  = 1920;
        windowHeight = 1080;
    }
    
    else if (BUILD_MODE == DEVELOPMENT) {
        windowWidth  = 1200;
        windowHeight = 648;
    }
    
    // Initialise Subsystems
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
    state = RUNNING;
    
    // give me an actor
    worldActors.insert(std::pair<actorID, Actor*>(0, new Actor()));
    worldActors.insert(std::pair<actorID, Actor*>(1, new Player()));
    
    // init them
    for (int i = 0; i < worldActors.size(); i++) worldActors.at(i)->init();

}

Game::~Game() {

}

/** 
 *  Game Loop
 */
void Game::begin() {
    glClearColor (0.075f, 0.075f, 0.075f, 0.0f);
    
    while (windowAlive()) {
        switch (state) {
            case MENU:
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                // menu interactions
                for (int i = 0; i < worldActors.size(); i++) worldActors.at(i)->update();
                
                glfwSwapBuffers(window);
                break;
            case RUNNING:
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                // render actors
                for (int i = 0; i < worldActors.size(); i++) worldActors.at(i)->update();
                
                glfwSwapBuffers(window);
                break;
            case PAUSED:
                
                // pause menu
                
                glfwWaitEvents();
                break;
            case ENDED:
                break;
        }
    }
}

void Game::end() {
    state = ENDED;
}

void Game::pause() {
    // toggle pause on and off
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
    glfwWindowHint   (GLFW_MAXIMIZED, GL_TRUE);                        // Stick to corner
    glfwWindowHint   (GLFW_SAMPLES, 4);                                // Multisampling
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
    glEnable    (GL_MULTISAMPLE);   // MULTISAMPLING
    glEnable    (GL_BLEND);         // TEXT BLENDING
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}

bool Game::windowAlive() {
    return !glfwWindowShouldClose(window);
}
