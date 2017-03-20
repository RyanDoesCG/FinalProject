//
//  Butterfly.hpp
//  WorldGenerator
//
//  Created by user on 18/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Butterfly_hpp
#define Butterfly_hpp

#include "GraphicsObject.hpp"
#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "GameObject.hpp"

class Butterfly: public GameObject {
    public:
        Butterfly (GraphicsEngine* g, PhysicsEngine* p);
       ~Butterfly ();
    
        virtual void update (State state) override;
    
    private:
        GraphicsObject* leftWing;
        GraphicsObject* rightWing;
    
        glm::vec3 direction;
    
        glm::mat4 model;
};

#endif /* Butterfly_hpp */
