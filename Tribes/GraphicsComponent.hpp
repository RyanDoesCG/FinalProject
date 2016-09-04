/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GraphicsComponent.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GraphicsComponent_hpp
#define GraphicsComponent_hpp

#include "Shader.hpp"
#include "Mesh.hpp"

#include <iostream>
#include <unordered_map>

class GraphicsComponent {
    public:
        virtual void render ();
    
    private:
        Mesh* mesh;
};

#endif /* GraphicsComponent_hpp */
