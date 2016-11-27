/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Vertex_hpp
#define Vertex_hpp

#include "../glm/glm.hpp"
using namespace glm;

struct Vertex {
    vec3 Position;
    vec3 Normal;
    vec2 TC;
};

#endif
