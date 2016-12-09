#ifndef Renderer_hpp
#define Renderer_hpp

#include "SceneCamera.hpp"
#include <vector>

typedef std::vector<Actor*> Scene;

class Renderer {
    public:
        Renderer(SceneCamera* cam);
        ~Renderer();
    
        void addToScene (Actor* actor);
        void drawScene (GameState state);
    
    private:
        Scene scene;
        SceneCamera* camera;
    
};

#endif /* Renderer.hpp */
