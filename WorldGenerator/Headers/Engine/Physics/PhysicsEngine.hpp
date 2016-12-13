#ifndef PhysicsEngine_hpp
#define PhysicsEngine_hpp

#include "../Actors/SceneCamera.hpp"
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
