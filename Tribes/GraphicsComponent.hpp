/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GraphicsComponent.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GraphicsComponent_hpp
#define GraphicsComponent_hpp

#include <iostream>

#include "Shader.hpp"
#include "Mesh.hpp"

class GraphicsComponent {
    public:
        GraphicsComponent  () {}
        ~GraphicsComponent () {}
    
        virtual void draw();

        Shader* objectShader;
        Mesh* objectMesh;
};

#endif /* GraphicsComponent_hpp */
