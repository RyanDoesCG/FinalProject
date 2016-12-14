/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsEngine.hpp
 *  Tribes
 *
 *  Created by ryan needham on 30/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PhysicsEngine_hpp
#define PhysicsEngine_hpp

#include "../Actors/Actor.hpp"
#include <vector>

typedef std::vector<Actor*> World;

class PhysicsEngine {
    public:
         PhysicsEngine();
        ~PhysicsEngine();
    
        void addToSimulation (Actor* actor);
        void simulate        (double time, GameState state);
    
    private:
        World physicsWorld;

};

#endif /* PhysicsEngine.hpp */
