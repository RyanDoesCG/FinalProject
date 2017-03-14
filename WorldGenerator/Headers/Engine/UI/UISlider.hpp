//
//  UISlider.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UISlider_hpp
#define UISlider_hpp

#include "GameObject.hpp"
#include "UIBox.hpp"

class UISlider: public GameObject {
    public:
         UISlider (GraphicsEngine* graph, PhysicsEngine* phys);
        ~UISlider ();
        
        virtual void update () override;
        
        void moveTo  (glm::vec3 p);
        void scaleTo (glm::vec3 s);
        void setColour (glm::vec4 c);
        void setAlpha  (GLfloat a);
        
        bool isSelected ();
        
        void fadeIn  ();
        void fadeOut ();
        
        void activatePhysics   ();
        void deactivatePhysics ();
        
    private:
        UIBox marker;
        
        glm::vec3 litColour;
        glm::vec3 unlitColour;
};

#endif /* UISlider_hpp */
