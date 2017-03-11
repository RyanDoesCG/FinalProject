//
//  UIBox.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UIBox_hpp
#define UIBox_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"

#include "GraphicsObject.hpp"
#include "PhysicsObject2D.hpp"

#include "GameObject.hpp"

class UIBox: public GameObject {
    public:
        UIBox (GraphicsEngine* graph, PhysicsEngine* phys);
       ~UIBox ();
    
        virtual void update () override;
    
        void moveTo  (glm::vec3 p);
        void scaleTo (glm::vec3 s);
        void setColour (glm::vec4 c);
        void setAlpha  (GLfloat a);
    
        bool isSelected ();
    
        void fadeIn  ();
        void fadeOut ();
    
    private:
        GraphicsObject* graphics;
        PhysicsObject2D* physics;

        glm::vec3 litColour;
        glm::vec3 unlitColour;
};

#endif /* UIBox_hpp */
