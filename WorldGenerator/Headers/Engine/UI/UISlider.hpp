//
//  UISlider.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UISlider_hpp
#define UISlider_hpp

#include "SafeCounter.hpp"
#include "GameObject.hpp"
#include "UIBoxBackground.hpp"
#include "UIBox.hpp"

class UISlider: public GameObject {
    public:
         UISlider (GraphicsEngine* graph, PhysicsEngine* phys);
        ~UISlider ();
        
        virtual void update (State state) override;
        
        void moveTo    (glm::vec3 p);
        void scaleTo   (glm::vec3 s);
        void setColour (glm::vec4 c);
        void setAlpha  (GLfloat a);
        
        bool isSelected ();
        bool isHidden = false;
        
        void fadeIn  ();
        void fadeOut ();
        
        void activatePhysics   ();
        void deactivatePhysics ();
    
        float getValue ();
        
    private:
        SafeCounter value_counter;
        SafeCounter position_counter;
    
        UIBox marker;
        UIBoxBackground range;
        
        glm::vec3 litColour;
        glm::vec3 unlitColour;
    
        Mouse* mouse;
        GLfloat lastMouseX;

};

#endif /* UISlider_hpp */
