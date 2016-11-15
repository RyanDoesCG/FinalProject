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
#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/HUD.hpp"

// Deterines window size/debug hud
#define BUILD_MODE 1

Game::Game() {
    srand(generateSeed());
    
    // decide what window to build
    switch (BUILD_MODE) {
        case CINEMATIC:
            windowWidth  = 1920;
            windowHeight = 1080;
            break;
        case DEVELOPMENT:
            windowWidth  = 800;
            windowHeight = 460;
            break;
    }
    
    // Initialise Subsystems
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
    state = IN_GAME;
    
    // give me an actor
    worldActors.insert(std::pair<actorID, Actor*>(0, new Player(window, this)));
    worldActors.insert(std::pair<actorID, Actor*>(1, new Planet()));
    worldActors.insert(std::pair<actorID, Actor*>(2, new HUD(window, this)));
    
}

Game::~Game() {

}

/** 
 *  Game Loop
 */
void Game::begin() {
    glClearColor (0.18f, 0.18f, 0.18f, 1.0f);
    
    // initialise actors
    for (int i = 0; i < worldActors.size(); i++)
        worldActors.at(i)->init();
    
    while (windowIsAlive()) {
        if (state == GAME_OVER) {
            glfwTerminate();
        }
        
        else {
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            for (int i = 0; i < worldActors.size(); i++)
                worldActors.at(i)->update(state);
            
            glfwSwapBuffers(window);
        }
    }
}

void Game::end() {
    glfwSetWindowShouldClose(window, GL_TRUE);
    state = GAME_OVER;
}

void Game::pause() {
    // toggle pause on and off
    (state == IN_GAME) ? state = IN_GAME_PAUSED : state = IN_GAME;
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

bool Game::windowIsAlive() {
    return !glfwWindowShouldClose(window);
}
