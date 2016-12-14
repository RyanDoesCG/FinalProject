/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Renderer.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Renderer_hpp
#define Renderer_hpp

#include "../Actors/Quad.hpp"
#include "../Actors/SceneCamera.hpp"
#include "../../GLFW/glfw3.h"
#include <vector>

typedef std::vector<Actor*> Scene;

class Renderer {
    public:
        Renderer(int width, int height);
        ~Renderer();
    
        void addToScene (Actor* actor);
        void drawScene (SceneCamera* camera);
    
    private:
        void setupFrameBufferObject(int width, int height);
        void setupColourBuffer();
        void setupDepthBuffer();
    
        Scene scene;
        SceneCamera* camera;
    
        GLuint FBO; // FrameBufferObject
        GLuint RBO; // RenderBufferObject
    
        GLuint colourAttachment;
        Quad processedScene;
    
        int width;
        int height;
    
};

#endif /* Renderer.hpp */
