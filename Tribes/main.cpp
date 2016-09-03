//
//  main.cpp
//  Tribes
//
//  Created by ryan needham on 01/09/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

// Sphere: http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere

#include "Game.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Game* game = new Game();
    game->begin();
    
    free(game);
    return 0;
}
