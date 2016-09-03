/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GameObject_hpp
#define GameObject_hpp

#include "Transform.hpp"
#include "glm/vec3.hpp"
#include "Mesh.hpp"

#include <iostream>

class GameObject {
    public:
        GameObject  ();
        ~GameObject ();
    
        void update ();
        void render ();

    private:
        glm::vec3* position;
        Transform* transform;

};

#endif /* GameObject_hpp */
