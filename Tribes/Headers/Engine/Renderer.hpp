#ifndef Renderer_hpp
#define Renderer_hpp

#include "SceneCamera.hpp"
#include "../GLFW/glfw3.h"
#include <vector>

typedef std::vector<Actor*> Scene;

class Renderer {
    public:
        Renderer(int width, int height, SceneCamera* cam);
        ~Renderer();
    
        void addToScene (Actor* actor);
        void drawScene (GameState state);
    
    private:
        Scene scene;
        SceneCamera* camera;
    
        GLuint FBO; // FrameBufferObject
        GLuint RBO; // RenderBufferObject
    
        GLuint colourAttachment;
    
};

#endif /* Renderer.hpp */
