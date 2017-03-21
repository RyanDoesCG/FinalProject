//
//  ChunkCollider.hpp
//  WorldGenerator
//
//  Created by user on 21/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ChunkCollider_hpp
#define ChunkCollider_hpp

#include "PhysicsObject3D.hpp"
#include <string>

class ChunkCollider: public PhysicsObject3D {
    public:
        ChunkCollider (glm::vec3 pos);
       ~ChunkCollider ();
    
        void simulate (double time) override;
        bool isColliding (PhysicsObject3D* other) override;
    
        void scaleTo (glm::vec3 s) override;
        void moveTo  (glm::vec3 p) override;
    
        glm::vec3 pos () override;
    
        bool touchingLeft ();
        bool touchingRight ();
        bool touchingTop ();
        bool touchingBottom ();

    private:
        float width;
        float depth;
    
        // for candidate finding
        bool contactLeft;
        bool contactRight;
        bool contactTop;
        bool contactBottom;
};

#endif /* ChunkCollider_hpp */
