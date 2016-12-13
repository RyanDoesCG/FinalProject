/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Vertex.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Vertex_hpp
#define Vertex_hpp

#include "../../glm/glm.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 colour;
};

#endif
