//
//  GraphicsObject.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef GraphicsObject_hpp
#define GraphicsObject_hpp
#include "Geometry.hpp"
#include "Material.hpp"
#include "glm.hpp"

class GraphicsObject {
    public:
        GraphicsObject ();
       ~GraphicsObject ();
    
        virtual void draw () = 0;
    
        Geometry geometry;
        Material material;
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
    
};

#endif /* GraphicsObject_hpp */
