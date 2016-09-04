/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsComponent.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PhysicsComponent_hpp
#define PhysicsComponent_hpp

#include <iostream>

// abstract class to be extended by implementations
class PhysicsComponent {
    public:
        virtual void update (float time);
        
    private:
        float weight;
};

#endif /* PhysicsComponent_hpp */
