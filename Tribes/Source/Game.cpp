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
#include "../Headers/Engine/Lamp.hpp"
#include "../Headers/Engine/Planet.hpp"
#include "../Headers/Engine/MainMenu.hpp"
#include "../Headers/Engine/GameHUD.hpp"
#include "../Headers/Engine/Skybox.hpp"
#include "../Headers/Engine/Moon.hpp"
#include "../Headers/Engine/Renderer.hpp"
#include "../Headers/Engine/PhysicsEngine.hpp"

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
    
    Player player = Player(window, this);
    Planet planet = Planet();
    Moon   moon1  = Moon();
    Moon   moon2  = Moon();
    Lamp   lamp   = Lamp();
    
    MainMenu menu = MainMenu(windowWidth, windowHeight, this);
    menu.show();
    
    GameHUD hud = GameHUD(windowWidth, windowHeight, this, &player, &planet);
    
    Renderer graphics = Renderer(windowWidth, windowHeight, player.getView());
    graphics.addToScene(&player);
    graphics.addToScene(&planet);
    graphics.addToScene(&moon1);
    graphics.addToScene(&moon2);
    graphics.addToScene(&lamp);
    
    PhysicsEngine physics = PhysicsEngine();
    physics.addToSimulation(&player);
    physics.addToSimulation(&planet);
    physics.addToSimulation(&moon1);
    physics.addToSimulation(&moon2);
    physics.addToSimulation(&lamp);

    lamp.setPosition (glm::vec3(-50, 0.0, 1.5));
    lamp.setScale    (0.25f);
    lamp.setColour   (glm::vec3(1.0, 0.9, 0.9));    // slight red tinge to light
    
    planet.setLight(&lamp);
    moon1.setLightSource(&lamp);
    moon2.setLightSource(&lamp);
    moon2.setPosition(glm::vec3(-1, -0.2, 0.0));
    moon2.setSpeed(12);
    moon2.setColour(glm::vec3(0.45, 0.175, 0.175));
    
    while (windowIsAlive()) {
        switch (state) {
            case MAIN_MENU: case LOAD_GAME: case OPTIONS: {
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                physics.simulate(glfwGetTime(), state);
                graphics.drawScene(state);
                
                // draw UI
                menu.update();
                
                glfwSwapBuffers(window);
                break;
            }
            case RUNNING_EDITMODE: case RUNNING_FREEMODE: {
                glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                
                physics.simulate(glfwGetTime(), state);
                graphics.drawScene(state);
                
                // get some distances
                vec3 dist = player.getPosition() - planet.getPosition();
                float a_to_b = sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);

                vec3 dist2 = player.getPosition() - moon1.getPosition();
                float a_to_c = sqrt(dist2.x * dist2.x + dist2.y * dist2.y + dist2.z * dist2.z);
                
                // print the closest
                (a_to_b < a_to_c) ?
                    player.setPosition(planet.getPosition())
                :
                    player.setPosition(moon1.getPosition());
                
                // draw UI
                hud.update(state, player.getView());
                
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
