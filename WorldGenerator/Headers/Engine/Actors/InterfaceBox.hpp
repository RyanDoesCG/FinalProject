//
//  InterfaceBox.hpp
//  WorldGenerator
//
//  Created by user on 07/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef InterfaceBox_hpp
#define InterfaceBox_hpp

#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "PhysicsEngine.hpp"
#include "PhysicsObject.hpp"
#include "GameObject.hpp"

class InterfaceBox: public GameObject {
    public:
        InterfaceBox (GraphicsEngine* g, PhysicsEngine* p);
       ~InterfaceBox ();
    
       virtual void update () override;
       
    private:
        GraphicsObject* graphics;
        PhysicsObject2D*  physics;
    
};

#endif /* InterfaceBox_hpp */
