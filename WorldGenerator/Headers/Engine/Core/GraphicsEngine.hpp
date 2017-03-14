//
//  GraphicsEngine.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GraphicsEngine_hpp
#define GraphicsEngine_hpp

#include "QuadGeometry.hpp"
#include "GraphicsObject.hpp"
#include "Camera.hpp"
#include <vector>

class GraphicsEngine {
    public:
        GraphicsEngine (float width, float height);
       ~GraphicsEngine ();
    
        void initPostProcessing ();
    
        void render();
    
        void add     (GraphicsObject* object);
        void addToUI (GraphicsObject* object);
    
    private:
        void offScreen ();
        void onScreen  ();
    
        void prerender       ();
        void renderScene     ();
        void renderUI        ();
    
        std::vector<GraphicsObject*> scene;
        std::vector<GraphicsObject*> ui;
    
        void buildFrameBuffer  ();
        void buildColourBuffer ();
        void buildDepthBuffer  ();
    
        Camera* camera;
    
        int windowWidth;
        int windowHeight;
    
        GLuint FBO; // FrameBufferObject
        GLuint RBO; // RenderBufferObject
    
        GLuint colourAttachment;
        GraphicsObject* frame;
};

#endif /* GraphicsEngine_hpp */
