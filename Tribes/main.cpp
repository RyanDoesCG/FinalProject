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
    
    // seed random generator ONCE PER RUN
    srand(static_cast<unsigned int>(time(0)));
    
    // test planets
    Planet* planet1 = new Planet(TOUGH);
    Planet* planet2 = new Planet(TOUGHER);
    Planet* planet3 = new Planet(TOUGHEST);
    
    std::cout<<"\n--\n"<< planet1->toString();
    std::cout<<"\n--\n"<< planet2->toString();
    std::cout<<"\n--\n"<< planet3->toString();
    
    free(planet1);
    free(planet2);
    free(planet3);
    return 0;
}

/* 


*/


