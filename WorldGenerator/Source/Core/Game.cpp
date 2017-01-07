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
#include "../../Headers/Engine/Physics/PhysicsEngine.hpp"

#include "../../Headers/Engine/Actors/Sun.hpp"
#include "../../Headers/Engine/Actors/Planet.hpp"
#include "../../Headers/Engine/Actors/Skybox.hpp"
#include "../../Headers/Engine/Actors/Moon.hpp"
#include "../../Headers/Engine/Actors/Cube.hpp"
#include "../../Headers/Engine/Actors/Skybox.hpp"
#include "../../Headers/Engine/Actors/Cursor.hpp"

#include "../../Headers/Engine/UI/GameHUD.hpp"
#include "../../Headers/Engine/UI/MainMenu.hpp"

#include "../../Headers/Engine/Utility/Input.hpp"

// Deterines window size/debug hud
#define BUILD_MODE 0

Game::Game() {
    srand(generateSeed());
    
    windowWidth  = 1920;
    windowHeight = 1080;
    
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
    glClearColor (0.12f, 0.12f, 0.12f, 1.0f);
    Input::initialise(window);
    
    Skybox skybox = Skybox();
    Player player = Player(window, this);
    Cursor cursor = Cursor();
    Planet planet = Planet();
    Moon   moon1  = Moon();
    Moon   moon2  = Moon();
    Sun    sun    = Sun();
    
    MainMenu menu = MainMenu(windowWidth, windowHeight, this);
    menu.show();
    
    GameHUD hud = GameHUD(windowWidth, windowHeight, this, &player, &planet);
    
    Cube cube = Cube();
    cube.setScale(2);
    cube.setColour(glm::vec3(1.0, 0.0, 0.0));
    
    Renderer graphics = Renderer(windowWidth, windowHeight);
    //graphics.addToScene(&skybox);
    graphics.addToScene(&planet);
    graphics.addToScene(&player);
    graphics.addToScene(&moon1);
    graphics.addToScene(&moon2);
    graphics.addToScene(&sun);
    //graphics.addToScene(&cube);
    
    PhysicsEngine physics = PhysicsEngine();
    //physics.addToSimulation(&skybox);
    physics.addToSimulation(&player);
    physics.addToSimulation(&planet);
    physics.addToSimulation(&moon1);
    physics.addToSimulation(&moon2);
    physics.addToSimulation(&sun);
    //physics.addToSimulation(&cube);

    sun.setPosition (glm::vec3(-50, 1.0, 1.5));
    sun.setScale    (0.25f);
    sun.setColour   (glm::vec3(1.0, 0.9, 0.9));    // slight red tinge to light
    
    planet.setLight(&sun);
    moon1.setLightSource(&sun);
    moon2.setLightSource(&sun);
    moon2.setPosition(glm::vec3(-1, -0.2, 0.0));
    moon2.setSpeed(12);
    moon2.setColour(glm::vec3(0.45, 0.175, 0.175));
    
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
                
                // draw UI
                hud.update(state);
                hud.draw (player.getView());
                
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
