//
//  Candidate.hpp
//  WorldGenerator
//
//  Created by user on 20/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Candidate_hpp
#define Candidate_hpp

#include "GraphicsEngine.hpp"
#include "GraphicsObject.hpp"
#include "GameObject.hpp"

class Candidate: public GameObject {
    public:
        Candidate (GraphicsEngine* g);
       ~Candidate ();
    
        void update (State state) override;
        void recycleAt (glm::vec3 newPos);
    
        float distanceToCamera;
    
        bool operator < (const Candidate& that) const;
    
    private:
        GraphicsObject* graphics;
    
};


#endif /* Candidate_hpp */
