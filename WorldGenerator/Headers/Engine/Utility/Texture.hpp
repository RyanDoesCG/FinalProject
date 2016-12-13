/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Texture.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Texture_hpp
#define Texture_hpp

#include "../../assimp/scene.h"
#include "../../glm/glm.hpp"
using namespace std;

struct Texture {
    GLuint id;
    string type;
//    aiString path;
};

#endif
