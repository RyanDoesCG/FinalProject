/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Window.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/GLEW/glew.h"
#include "../Headers/GLFW/glfw3.h"
#include "../Headers/Engine/Window.hpp"

Window::Window(int width, int height, const std::string& title) {

    this->width  = width;
    this->height = height;
    this->title  = title;

    if (initGLFW()) {std::cout << "SDL initialisation failure. Exiting\n";  exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure. Exiting\n"; exit(1);}
    
    randomiseClearColour();
}

Window::~Window() {
    glfwTerminate();
}

int Window::initGLFW() {
    // start glfw Subsystem
    if (glfwInit() == GLFW_FALSE) return 1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL Version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);                  // OpenGL Version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // OpenGL Profile
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);                        // Resizable Window
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);                     // Double Buffering
   // glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);                        // Stick to corner
    glfwWindowHint(GLFW_SAMPLES, 4);                                // Multisampling
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // macOS requires this
    glfwSwapInterval(1);                                            // enable VSYNC

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) return 1;
    
    glfwMakeContextCurrent(window);
    
    return 0;
}

int Window::initGLEW() {
    // initialise GLEW
    GLenum error = glewInit();
    if (error) return 1;

    // viewport
    glfwGetFramebufferSize (window, &width, &height);
    glViewport (0, 0, width, height);
 
    glEnable    (GL_DEPTH_TEST);    // Z BUFFERING
    glEnable    (GL_MULTISAMPLE);   // MULTISAMPLING
    glEnable    (GL_BLEND);         // TEXT BLENDING
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 0;
}

void Window::randomiseClearColour () {
    clearColour = glm::vec4(
        0.05, //(rand() % 100) / 100.0f,
        0.05, //(rand() % 100) / 100.0f,
        0.05, //(rand() % 100) / 100.0f,
        0
    );
}

bool Window::finished() {
    return glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
}

void Window::clear() {
    glClearColor (clearColour.x, clearColour.y, clearColour.z, clearColour.w);
    glClear      (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
