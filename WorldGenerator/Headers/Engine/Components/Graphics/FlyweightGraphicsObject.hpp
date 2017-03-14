//
//  FlyweightGraphicsObject.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef FlyweightGraphicsObject_hpp
#define FlyweightGraphicsObject_hpp

#include "GraphicsObject.hpp"
#include "FlyweightInstance.hpp"
#include "glm.hpp"

class FlyweightGraphicsObject: public GraphicsObject {
    public:
        FlyweightGraphicsObject (Geometry* geom, Material* mat): GraphicsObject(geom, mat) {}
       ~FlyweightGraphicsObject () {}
    
        virtual void draw (Camera* cam) override {
            for (FlyweightInstance& i : instances) {
                GraphicsObject::position = i.position;
                GraphicsObject::rotation = i.rotation;
                GraphicsObject::colour   = i.colour;
                GraphicsObject::scale    = i.scale;
                GraphicsObject::draw(cam);
            }
        }
    
        std::vector<FlyweightInstance> instances;
};

#endif /* FlyweightGraphicsObject_hpp */
