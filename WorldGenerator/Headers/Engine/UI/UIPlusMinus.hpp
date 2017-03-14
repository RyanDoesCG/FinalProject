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

class UIPlusMinus: public UIBox {
    public:
        UIPlusMinus (GraphicsEngine* graph, PhysicsEngine* phys);
       ~UIPlusMinus ();
    
        virtual void update () override;
    
    private:
    
        UIBox plusButton;
        UIBox minusButton;
};


#endif /* UIPlusMinus_hpp */
