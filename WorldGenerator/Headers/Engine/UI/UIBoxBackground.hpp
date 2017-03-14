//
//  UIBoxBackground.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef UIBoxBackground_hpp
#define UIBoxBackground_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"

#include "GraphicsObject.hpp"
#include "PhysicsObject2D.hpp"

#include "GameObject.hpp"

class UIBoxBackground: public GameObject {
    public:
        UIBoxBackground (GraphicsEngine* graph);
       ~UIBoxBackground ();
    
        virtual void update () override;
    
        void moveTo    (glm::vec3 p);
        void scaleTo   (glm::vec3 s);
        void setColour (glm::vec4 c);
        void setAlpha  (GLfloat a);
    
    private:
        GraphicsObject* graphics;
};

#endif /* UIBoxBackground_hpp */
