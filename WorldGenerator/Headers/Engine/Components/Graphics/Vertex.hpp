//
//  Vertex.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>
#include "glm.hpp"

struct Vertex {
    Vertex (glm::vec3 pos, glm::vec3 norm, glm::vec2 tc) {
        position = pos;
        normal   = norm;
        uv       = tc;
    }

    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
  
    
    std::string string () {
        return
            std::string("(" +
            std::to_string(position.x) + ", " +
            std::to_string(position.y) + ", " +
            std::to_string(position.z) + ")");
    }
};

#endif /* Vertex_hpp */
