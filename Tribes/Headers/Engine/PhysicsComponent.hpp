/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsComponent.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PhysicsComponent_hpp
#define PhysicsComponent_hpp

#include <iostream>

/** 
 *  PhysicsComponent Class
 *
 */
class PhysicsComponent {
    public:
        virtual void update() {
            std::cout << "Physics not implemented" << std::endl;
        };
};

#endif /* PhysicsComponent_hpp */
