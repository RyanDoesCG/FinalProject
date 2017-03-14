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
    
        enum Effect { blur, fade };
    
        void initPostProcessing ();
    
        void render();
    
        void setEffect (Effect e);
    
        void add     (GraphicsObject* object);
        void addToUI (GraphicsObject* object);
    
    private:
        void offScreen ();
        void onScreen  ();
        void renderShadows ();
    
        void prerender       ();
        void renderScene     ();
        void renderUI        ();
    
        std::vector<GraphicsObject*> scene;
        std::vector<GraphicsObject*> ui;
    
        void buildFrameBuffer  ();
        void buildColourBuffer ();
        void buildDepthBuffer  ();
    
        void buildShadowDepthBuffer ();
    
        Camera* camera;
    
        int windowWidth;
        int windowHeight;
    
        GLuint FBO; // FrameBufferObject
        GLuint RBO; // RenderBufferObject
    
        GLuint depthFBO; // for shadow mapping
        GLuint depthTexture;
    
        Effect currentEffect;
    
        GLuint colourAttachment;
        GraphicsObject* frame;
};

#endif /* GraphicsEngine_hpp */
