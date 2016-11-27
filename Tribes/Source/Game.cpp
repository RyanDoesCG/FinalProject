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
#include "../Headers/Engine/HUD.hpp"
#include "../Headers/Engine/SceneCamera.hpp"

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
    glClearColor (0.2f, 0.2f, 0.2f, 1.0f);
    int gameTick = 0;
    
    Player player = Player(window, this);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    GLuint VAO;
    GLuint VBO;
    
    Mesh lamp   = Mesh();
    Mesh object = Mesh();
    
    lamp.position = glm::vec3(-0.75, -0.75, 0.75);
    object.position = glm::vec3(0.75, 0.0, 0.0);
    
    lamp.scale = glm::vec3(0.5, 0.5, 0.5);
    object.scale = glm::vec3(1.3, 1.3, 1.3);
    
    lamp.color = glm::vec3(1.0, 1.0, 1.0);
    object.color = glm::vec3(1.0, 0.25, 0.25);

    ShaderComponent* lampShader  = new ShaderComponent("lightSource");
    ShaderComponent* lightableShader = new ShaderComponent("litObject");
    
    glUniform3fv(glGetUniformLocation(lightableShader->getProgramID(), "lightColour"), 1, glm::value_ptr(lamp.color));
    glUniform3fv(glGetUniformLocation(lightableShader->getProgramID(), "lightPosition"), 1, glm::value_ptr(lamp.position));
    
    while (windowIsAlive()) {
        
        if (state == GAME_OVER) {
            glfwTerminate();
        }
        
        else {
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            player.update(state);
            
            lamp.testdraw(lampShader, player.getView());
            object.testdraw(lightableShader, player.getView());
            
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
