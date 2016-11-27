/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 *  DONT FORGET WARNINGS ARE SUPPRESSED
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/Game.hpp"
#include "../Headers/Engine/Player.hpp"
#include "../Headers/Engine/Cube.hpp"
#include "../Headers/Engine/Lamp.hpp"
#include "../Headers/Engine/HUD.hpp"
#include "../Headers/Engine/Model.hpp"

// Deterines window size/debug hud
#define BUILD_MODE 0

Game::Game() {
    srand(generateSeed());
    
    // decide what window to build
    switch (BUILD_MODE) {
        case CINEMATIC:
            windowWidth  = 1920;
            windowHeight = 1080;
            break;
        case DEVELOPMENT:
            windowWidth  = 1200;
            windowHeight = 620;
            break;
    }
    
    // Initialise Subsystems
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
    state = IN_GAME;
    
}

Game::~Game() {

}

/** 
 *  Game Loop
 */
void Game::begin() {
    glClearColor (0.12f, 0.12f, 0.12f, 1.0f);
    
    Player player = Player(window, this);

    Lamp   lamp   = Lamp();
    Cube   object1 = Cube();
    Cube   object2 = Cube();
    Cube   object3 = Cube();
    
    lamp.setPosition (glm::vec3(-1, 1, 0.5));
    lamp.setScale    (0.25f);
    lamp.setColour   (glm::vec3(0.75, 0.32, 0.46));
    
    object1.setPosition (glm::vec3(1.42, 0.0, 0.0));
    object1.setScale    (1.0f);
    object1.setColour   (glm::vec3(0.25, 0.75, 0.75));
    object1.setLightSource(&lamp);
    
    object2.setPosition (glm::vec3(0.0, 0.0, 0.0));
    object2.setScale    (1.2f);
    object2.setColour   (glm::vec3(1.0, 0.25, 0.25));
    object2.setLightSource(&lamp);
    
    object3.setPosition (glm::vec3(-1.42, 0.0, 0.0));
    object3.setScale    (1.0f);
    object3.setColour   (glm::vec3(0.25, 0.75, 0.75));
    object3.setLightSource(&lamp);

    while (windowIsAlive()) {

        if (state == GAME_OVER) {
            glfwTerminate();
        }

        else {
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            lamp.explore(glfwGetTime());
            
            player.update  (state, player.getView());
            lamp.update    (state, player.getView());
            object1.update (state, player.getView());
            object2.update (state, player.getView());
            object3.update (state, player.getView());
    
            
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
    //glfwWindowHint   (GLFW_MAXIMIZED, GL_TRUE);                        // Stick to corner
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
