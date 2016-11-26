/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "../glm/glm.hpp"
using namespace glm;

struct Vertex {
    vec3 Position;
    vec3 Normal;
    vec2 TC;
};

#endif
