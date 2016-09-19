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

#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"
#include <iostream>

class GraphicsComponent {
    public:
        GraphicsComponent  () {}
        ~GraphicsComponent () {}
    
        void addShader(Shader* s) { objectShaders.push_back(s); }
    
        virtual void draw();

    protected:
        std::vector<Shader*> objectShaders;
        Texture*             objectTexture;
        Mesh*                objectMesh;
};

#endif /* GraphicsComponent_hpp */
