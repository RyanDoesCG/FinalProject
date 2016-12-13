//
//  Showcase.cpp
//  Tribes
//
//  Created by user on 09/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Testing/Showcase.hpp"

#include "../../Headers/Engine/Core/Renderer.hpp"
#include "../../Headers/Engine/Actors/Player.hpp"
#include <iostream>

Showcase::Showcase () {
    srand(time(0));
    
    windowWidth  = 1920;
    windowHeight = 1080;
    
    // Initialise Subsystems
    if (initGLFW()) {std::cout << "GLFW initialisation failure. Exiting\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
}

Showcase::~Showcase () {
    
}

void Showcase::begin () {
/*
    SceneCamera camera = SceneCamera(windowWidth, windowHeight);
    Renderer graphics = Renderer(&camera);
    
    while (windowIsAlive()) {
        graphics.drawScene(RUNNING_FREEMODE);
    }
*/
}

void Showcase::pause () {
    
}

void Showcase::end () {
    
}

int Showcase::initGLFW () {
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

int Showcase::initGLEW () {
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

bool Showcase::windowIsAlive() {
    return !glfwWindowShouldClose(window);
}
