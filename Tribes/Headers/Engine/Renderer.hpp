#ifndef Renderer_hpp
#define Renderer_hpp

#include "Player.hpp"
#include <vector>

typedef std::vector<Actor*> Scene;

class Renderer {
    public:
        Renderer(Player* p);
        ~Renderer();
    
        void addToScene (Actor* actor);
        void drawScene (GameState state);
    
    private:
        Scene scene;
        Player* player;
    
};

#endif /* Renderer.hpp */
