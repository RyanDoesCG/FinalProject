//
//  PhysicsEngine.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef PhysicsEngine_hpp
#define PhysicsEngine_hpp

#include "PhysicsObject2D.hpp"
#include "PhysicsObject3D.hpp"
#include <vector>

class PhysicsEngine {
    public:
        PhysicsEngine ();
       ~PhysicsEngine ();
    
        void simulate (double time);
    
        void addTo2D (PhysicsObject2D* object);
        void addTo3D (PhysicsObject3D* object);
    
    private:
        std::vector<PhysicsObject2D*> world2D;
        std::vector<PhysicsObject3D*> world3D;
};

#endif /* PhysicsEngine_hpp */
