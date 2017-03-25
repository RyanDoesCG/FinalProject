//
//  ObjectSpawner.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ObjectSpawner_hpp
#define ObjectSpawner_hpp

#include "GraphicsEngine.hpp"
#include "FlyweightGraphicsObject.hpp"
#include "HeightMap.hpp"
#include "GameObject.hpp"
#include <vector>

class ObjectSpawner: public GameObject {
    public:
        ObjectSpawner () {}
       ~ObjectSpawner () {}
    
        virtual void update (State state) {}
    
        void addUniform1f (std::string name, GLfloat value) {
            sprite->addUniform1f(name, value);
        }
    
    protected:
        FlyweightGraphicsObject* sprite;
    
        int numObjects;
    
        std::vector<glm::vec3> concentrationPoints;
};

#endif /* ObjectSpawner_hpp */
