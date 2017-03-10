//
//  AACollisionBox2D.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef AACollisionBox2D_hpp
#define AACollisionBox2D_hpp

#include "PhysicsObject2D.hpp"

class AACollisionBox2D: public PhysicsObject2D {
    public:
        AACollisionBox2D (int w, int h);
       ~AACollisionBox2D ();
    
        virtual void simulate (double time) override;
        virtual bool isColliding (PhysicsObject2D* other) override;

    private:
        float width;
        float height;
};

#endif /* AACollisionBox2D_hpp */
