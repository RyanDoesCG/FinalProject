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

#include "Biome.hpp"

int main(int argc, const char * argv[]) {
/*    Game* game = new Game();
    game->begin();
    free(game);
*/
    Biome* test = new Biome();
    
    std::cout << "test --\n";
    std::cout << test->toString();
    
    return 0;
}
