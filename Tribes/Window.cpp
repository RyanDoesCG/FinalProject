/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Window.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "GLEW/glew.h"
#include "Window.hpp"
#include <Random>

Window::Window  (int width, int height, const std::string& title) {
    glewExperimental = GL_TRUE;  // Mesh Vertex Array initialisation doesn't work without this flag

    this->width = width;
    this->height = height;
    this->title = title;

    if (initSDL()) std::cout << "SDL initialisation failure\n";
    if (initGLEW()) std::cout << "GLEW initialisation failure\n";
    
    clearColor = new glm::vec4(0.3, 0.7, 0.6, 1);
    
    open = true;
    
    // improve and replace...
//    srand(static_cast<unsigned int>(time(0)));
//    clearColor = new glm::vec4 (
//        (float)(random() % 100) / rand(),
//        (float)(random() % 100) / rand(),
//        (float)(random() % 100) / rand(),
//        1
//    );
}

Window::~Window () {
    // delete stuff
    SDL_GL_DeleteContext (glContext);
    SDL_DestroyWindow    (window);
    
    // quit SDL
    SDL_Quit();
}

int Window::initSDL () {
    // start SDL Subsystem
    if (SDL_Init (SDL_INIT_EVERYTHING))
        return 1;
    
    // set 32-bit colour buffer
    SDL_GL_SetAttribute (SDL_GL_RED_SIZE,    8);
    SDL_GL_SetAttribute (SDL_GL_GREEN_SIZE,  8);
    SDL_GL_SetAttribute (SDL_GL_BLUE_SIZE,   8);
    SDL_GL_SetAttribute (SDL_GL_ALPHA_SIZE,  8);
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE,  16);
    SDL_GL_SetAttribute (SDL_GL_BUFFER_SIZE, 32);
    
    // Enable Double buffering
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
    
    // create window
    window = SDL_CreateWindow (
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );
    
    // create context
    glContext = SDL_GL_CreateContext (window);
    
    // hide mouse
    //SDL_ShowCursor(SDL_DISABLE);
    
    return 0;
}

int Window::initGLEW() {
    // initialise GLEW
    GLenum status = glewInit();
    
    if (status!=GLEW_OK)
        return 1;

    // face culling
    glEnable   (GL_CULL_FACE);
    glCullFace (GL_BACK);
    
    // Z-Buffering
    glEnable (GL_DEPTH_TEST);
    
    return 0;
}

void Window::update () {
    SDL_GL_SwapWindow (window);
}

void Window::clear  () {
    glClearColor (clearColor->x, clearColor->y, clearColor->z, clearColor->w);
    glClear      (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
