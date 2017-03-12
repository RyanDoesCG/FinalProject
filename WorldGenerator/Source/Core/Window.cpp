//
//  Window.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "Window.hpp"
#include <iostream>

Window::Window (int width, int height) {
    this->width  = width;
    this->height = height;
    
    if (initGLFW ()) std::cout << "GLFW ERROR" << std::endl;
    if (initGLEW ()) std::cout << "GLEW ERROR" << std::endl;
}

Window::~Window () {
    glfwDestroyWindow(window);
}

bool Window::isAlive() {
    return !glfwWindowShouldClose(window);
}

void Window::close() {
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void Window::swapBuffers () {
    glfwSwapBuffers(window);
}

int Window::initGLEW () {
    // initialise GLEW
    GLenum error = glewInit();
    if (error) return 1;
    
    // viewport
    glfwGetFramebufferSize (window, &width, &height);
    glViewport (0, 0, width, height);
    
    glEnable    (GL_DEPTH_TEST);
    glEnable    (GL_MULTISAMPLE);   // MULTISAMPLING
    glEnable    (GL_BLEND);         // ALPHA BLENDING
    //glEnable    (GL_CULL_FACE);
    //glCullFace  (GL_BACK);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    int vertexTexUnits;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &vertexTexUnits);
    std::cout << "\tVERTEX TEXTURE UNITS: " << vertexTexUnits << std::endl;
    std::cout << "\tUsing GLEW "  << glewGetString (GLEW_VERSION)  <<std::endl;
    std::cout << "\tVendor: "     << glGetString   (GL_VENDOR)     <<std::endl;
    std::cout << "\tRenderer: "   << glGetString   (GL_RENDERER)   <<std::endl;
    std::cout << "\tVersion: "    << glGetString   (GL_VERSION)    <<std::endl;
    std::cout << "\tGLSL: "       << glGetString   (GL_SHADING_LANGUAGE_VERSION)<<std::endl;
    std::cout << std::endl;
    
    return 0;
}

int Window::initGLFW () {
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
    //window = glfwCreateWindow(width, height, "Tribes - OpenGL", glfwGetPrimaryMonitor(), nullptr);
    window = glfwCreateWindow(width, height, "UIEngine", nullptr, nullptr);
    
    if (!window) return 1;
    
    glfwMakeContextCurrent(window);
    
    return 0;
}
