/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameObject.cpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "GameObject.hpp"

GameObject::GameObject  () {
    position = new glm::vec3(0, 0, 0);
    transform = new Transform();
}

GameObject::~GameObject () {
    free(position);
    free(transform);
}
