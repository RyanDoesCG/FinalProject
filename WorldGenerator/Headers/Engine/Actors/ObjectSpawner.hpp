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

#include "GameObject.hpp"

class ObjectSpawner: public GameObject {
    public:
        ObjectSpawner (GraphicsEngine* graph, std::string pathToModel, glm::vec4 col, int num);
       ~ObjectSpawner ();
    
        virtual void update (State state) override;
    
    private:
        FlyweightGraphicsObject* sprite;
    
        int numObjects;
};

#endif /* ObjectSpawner_hpp */
