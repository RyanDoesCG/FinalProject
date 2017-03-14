//
//  GameObject.hpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "State.hpp"
#include "glm.hpp"

class GameObject {
    public:
        GameObject () {}
       ~GameObject () {}
    
        glm::vec3 position;
        glm::vec3 scale;
    
        virtual void update (State state) = 0;

};

#endif /* GameObject_hpp */
