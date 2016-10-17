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

voidstar

*/

#include "../Headers/Engine/Game.hpp"
#include "../Headers/Engine/MathsToolkit.hpp"
#include <iostream>
#include <vector>

#define HEIGHT 100
#define WIDTH  100

int main(int argc, const char * argv[]) {
    Game game;
    game.begin();
    return 0;
}

/*
bool graph[WIDTH][HEIGHT];

graph[5][5]   = true;
graph[25][40] = true;
graph[45][5]   = true;

std::vector<glm::vec3> result = MathsToolkit::parseTriangle(glm::vec3(5, 5, 0), glm::vec3(25, 40, 0), glm::vec3(45, 5, 0));
int aX = result.at(0).x;
int aY = result.at(0).y;
int bX = result.at(1).x;
int bY = result.at(1).y;
int cX = result.at(2).x;
int cY = result.at(2).y;
int dX = result.at(3).x;
int dY = result.at(3).y;
int eX = result.at(4).x;
int eY = result.at(4).y;
int fX = result.at(5).x;
int fY = result.at(5).y;

graph[aX][aY] = true;
graph[bX][bY] = true;
graph[cX][cY] = true;
graph[dX][dY] = true;
graph[eX][eY] = true;
graph[fX][fY] = true;

plot ();

void plot () {
    for (int y = WIDTH; y > 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            if (graph[x][y]) std::cout << "*";
            else             std::cout << " ";
        }
        std::cout << std::endl;
    }
}

*/
