/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../assimp/scene.h"
#include "../glm/glm.hpp"
#include <iostream>
using namespace std;

struct Texture {
    GLuint id;
    string type;
    aiString path;
};

#endif
