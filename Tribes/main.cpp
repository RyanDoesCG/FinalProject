//
//  main.cpp
//  Tribes
//
//  Created by ryan needham on 01/09/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

// Sphere: http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere

#include "InputHandler.hpp"
#include "GameObject.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include <iostream>

#define SCREEN_WIDTH  683
#define SCREEN_HEIGHT 393
#define MAX_FPS       60

int main(int argc, const char * argv[]) {
    InputHandler * input  = new InputHandler();
    Window       * window = new Window(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Tribes"
    );
    
    // test planet gen
    Planet* testPlanet = new Planet();
    
    while (true) {
        input->checkInput();
        // update state
        window->clear();
        
        testPlanet->render();
        
        window->update();
    }

    free(window);
    return 0;
}
