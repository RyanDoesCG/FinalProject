/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsBox2D.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PhysicsBox2D_hpp
#define PhysicsBox2D_hpp

#include "../Components/Component.hpp"
#include "Intersection.hpp"
#include "../../GLM/glm.hpp"

class PhysicsBox2D : public Component {
    public:
        PhysicsBox2D(glm::vec3 minExtents, glm::vec3 maxExtents);
        ~PhysicsBox2D();
    
        virtual void init () override;
        virtual void update () override;
    
        Intersection detectIntersection (PhysicsBox2D* other);
    
        glm::vec3 getMinimumExtents () { return minimumExtents; }
        glm::vec3 getMaximumExtents () { return maximumExtents; }

    private:
        glm::vec3 maximumExtents;
        glm::vec3 minimumExtents;
};

#endif
