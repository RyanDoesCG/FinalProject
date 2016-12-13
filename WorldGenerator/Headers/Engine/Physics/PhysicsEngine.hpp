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

typedef std::vector<Actor*> Scene;

class PhysicsEngine {
public:
     PhysicsEngine();
    ~PhysicsEngine();
    
    void addToSimulation (Actor* actor);
    void simulate        (double time, GameState state);
    
private:
    Scene scene;

};

#endif /* PhysicsEngine.hpp */
