//
//  UIPlusMinus.hpp
//  WorldGenerator
//
//  Created by user on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UIPlusMinus_hpp
#define UIPlusMinus_hpp

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "PhysicsObject2D.hpp"
#include "AACollisionBox2D.hpp"
#include "GameObject.hpp"
#include "UIBox.hpp"
#include "UIBoxBackground.hpp"
#include "SafeCounter.hpp"

class UIPlusMinus: public GameObject {
public:
    UIPlusMinus (GraphicsEngine* graph, PhysicsEngine* phys);
    ~UIPlusMinus ();
    
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
    
private:
    SafeCounter counter;
    
    // visual
    UIBox plus;
    UIBox minus;
    UIBoxBackground frame;
    
    glm::vec3 litColour;
    glm::vec3 unlitColour;
    
    Mouse* mouse;
    GLfloat lastMouseX;
    
};


#endif /* UIPlusMinus_hpp */
