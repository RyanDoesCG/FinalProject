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

    if (initGLFW()) {std::cout << "SDL initialisation failure\n"; exit(1);}
    if (initGLEW()) {std::cout << "GLEW initialisation failure\n"; exit(1);}
    
    randomiseClearColour();
}

Window::~Window() {
    // delete context and window before
    // quitting SDL subsystems
    glfwTerminate();
}

int Window::initGLFW() {
    // start glfw Subsystem
    if (glfwInit() == GLFW_FALSE) return 1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    
    // multisampling
    glfwWindowHint(GLFW_SAMPLES, 4);
    
    // macOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, "tribes", nullptr, nullptr);
    
    if (!window) return 1;
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE; // Mesh Vertex Array initialisation doesn't work without this flag
    
    return 0;
}

int Window::initGLEW() {
    // initialise GLEW
    GLenum status = glewInit();
    
    if (status != GLEW_OK) return 1;

    // viewport
    glfwGetFramebufferSize(window, &width, &height);
    glViewport (0, 0, width, height);
 
    // face culling REMOVED: CAUSES THINGS TO NOT SHOW UP
//    glEnable   (GL_CULL_FACE);
//    glCullFace (GL_BACK);
    
    // Z-Buffering
    glEnable   (GL_DEPTH_TEST);
    glEnable   (GL_MULTISAMPLE);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
}

void Window::clear() {
    glClearColor (clearColour.x, clearColour.y, clearColour.z, clearColour.w);
    glClear      (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
