//
//  main.cpp
//  Tribes
//
//  Created by ryan needham on 01/09/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

// Sphere/Planet: http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere
// Sky/Terrain:   http://vterrain.org/Atmosphere/

/* 
IDEAS/TO-DO

Moon biome?
Space stations?
Custom RNG?

NAMES
Domhan      (world in gaelic)
PolyTerra   (many worlds in latin)

*/

#include "Game.hpp"
#include <iostream>

#include "Planet.hpp"
#include "Tribe.hpp"

int main(int argc, const char * argv[]) {
    // run the game
    Game* game = new Game();
    game->begin();
    free(game);
    return 0;
}

/* 


*/


