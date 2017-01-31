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
#include "../../Headers/Engine/Core/Game.hpp"
#include "../../Headers/Engine/Core/Renderer.hpp"
#include "../../Headers/Engine/UI/MainMenu.hpp"
#include "../../Headers/Engine/Utility/Input.hpp"
#include "../../Headers/Engine/Actors/Player.hpp"
#include "../../Headers/Engine/Physics/PhysicsEngine.hpp"

#include "../../Headers/Engine/Actors/GridPlane.hpp"
#include "../../Headers/Engine/Actors/Cube.hpp"

// Deterines window size/debug hud
#define BUILD_MODE 0

Game::Game() {
    srand(generateSeed());
    
    windowWidth  = 1280;
    windowHeight = 800;
    
    // Initialise Subsystems
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
    state = MAIN_MENU;
 
}

Game::~Game() {

}

/**
 *  Game Loop
 */
void Game::begin() {
    glClearColor (0.93f, 0.90f, 0.83f, 1.0f);
    Input::initialise(window);

    Player player = Player(window, this);
    MainMenu menu = MainMenu(windowWidth, windowHeight, this);
    menu.show();
    
    Renderer graphics = Renderer(windowWidth, windowHeight);
    PhysicsEngine physics = PhysicsEngine();
    
    // Skyland
    GridPlane worldGrid = GridPlane(56, 56);
    Cube cube = Cube();
    
    graphics.addToScene(&worldGrid);
    physics.addToSimulation(&worldGrid);
    
    graphics.addToScene(&cube);
    physics.addToSimulation(&cube);

    graphics.addToScene(&player);
    physics.addToSimulation(&player);
    
    state = RUNNING_FREEMODE;
    
    while (windowIsAlive()) {
        switch (state) {
            case MAIN_MENU: case LOAD_GAME: case OPTIONS: {
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                Input::update();
                physics.simulate(glfwGetTime(), state);
                graphics.drawScene(player.getView());
                
                // draw UI
                menu.update();
                
                glfwSwapBuffers(window);
                break;
            }
            case RUNNING_EDITMODE: case RUNNING_FREEMODE: {
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                Input::update();
                physics.simulate(glfwGetTime(), state);
                graphics.drawScene(player.getView());
                
                glfwSwapBuffers(window);
                break;
            }
            case PAUSED: {
                glfwPollEvents();
                break;
            }
            case OVER: {
                glfwTerminate();
                break;
            }
        }
    }
}

void Game::setState(GameState nextState) {
    state = nextState;
}

void Game::end() {
    glfwSetWindowShouldClose(window, GL_TRUE);
    state = OVER;
}

void Game::pause() {
    // toggle pause on and off
    (state == RUNNING_FREEMODE || state == RUNNING_EDITMODE) ? state = PAUSED : state = RUNNING_FREEMODE;
}

int Game::generateSeed() {
    srand(static_cast<unsigned int>(time(0)));
    seed = rand();
    std::cout << "World Seed: " << seed << std::endl <<std::endl;
    return seed;
}

void resizeFunction (GLFWwindow* window, int width, int height) {

}

int Game::initGLFW () {
    // start glfw Subsystem
    if (glfwInit() == GLFW_FALSE) return 1;
    
    glfwWindowHint   (GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL Version
    glfwWindowHint   (GLFW_CONTEXT_VERSION_MINOR, 2);                  // OpenGL Version
    glfwWindowHint   (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // OpenGL Profile
    glfwWindowHint   (GLFW_RESIZABLE, GL_TRUE);                        // Resizable Window
    glfwWindowHint   (GLFW_DOUBLEBUFFER, GL_TRUE);                     // Double Buffering
    glfwWindowHint   (GLFW_SAMPLES, 4);                                // Multisampling
    glfwWindowHint   (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // macOS requires this
    glfwSwapInterval (1);                                              // enable VSYNC

    // FULLSCREEN (buggy)
    //window = glfwCreateWindow(windowWidth, windowHeight, "Tribes - OpenGL", glfwGetPrimaryMonitor(), nullptr);
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
    
    glEnable    (GL_MULTISAMPLE);   // MULTISAMPLING
    glEnable    (GL_BLEND);         // ALPHA BLENDING
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}

bool Game::windowIsAlive() {
    return !glfwWindowShouldClose(window);
}
