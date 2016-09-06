//
//  main.cpp
//  Tribes
//
//  Created by ryan needham on 01/09/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

// Sphere/Planet: http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere
// Sky/Terrain:   http://vterrain.org/Atmosphere/

// Moon biome?

// Space stations?

#include "Game.hpp"
#include <iostream>

#include "Planet.hpp"

int main(int argc, const char * argv[]) {
    // run the game
    Game* game = new Game();
    game->begin();
    free(game);
    
    // test planet
    Planet* planet = new Planet(TOUGH);
    std::cout << "test--\n" << planet->toString();
    
    return 0;
}
