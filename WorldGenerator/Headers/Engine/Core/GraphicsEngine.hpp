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
#include "TextRenderer.hpp"
#include "Camera.hpp"
#include "State.hpp"
#include <map>

class GraphicsEngine {
    public:
        GraphicsEngine (float width, float height);
       ~GraphicsEngine ();
    
        enum Effect { blur, fade, none };
    
        void initPostProcessing ();
        void initTextRendering  ();
    
        void render    (State s);
    
        void setEffect (Effect e);
    
        void add       (GraphicsObject* object);
        void addLight  (GraphicsObject* object);
        void addToUI   (GraphicsObject* object);
        void addToText (std::string txt,
                        glm::vec2   pos,
                        float       scl,
                        glm::vec3   col);
    
        void remove       (int ID);
        void removeLight  (int ID);
        void removeFromUI (int ID);
    
        Camera* getSceneCamera();
    
    private:
        void prerender       (State s);
        void offScreen       ();
        void renderShadows   ();
        void renderScene     ();
        void onScreen        ();
        void renderUI        ();
        void renderText      ();
    
        struct depthTest {
            bool operator()(const GraphicsObject* a, const GraphicsObject* b) const {
                return a->position.z < b->position.z;
            }
        };

        std::map<GraphicsObject*, int> lights;
        std::map<GraphicsObject*, int> scene;
        std::map<GraphicsObject*, int> ui;
    
        void buildFrameBuffer  ();
        void buildColourBuffer ();
        void buildDepthBuffer  ();
    
        void buildShadowDepthBuffer ();
    
        Camera* sceneCamera; // used to render scene
        Camera* frameCamera; // used to render pp frame quad
    
        int windowWidth;
        int windowHeight;
    
        GLuint FBO; // FrameBufferObject
        GLuint RBO; // RenderBufferObject
    
        GLuint depthFBO; // for shadow mapping
        GLuint depthTexture;
    
        Effect currentEffect;
    
        GLuint colourAttachment;
        GraphicsObject* frame;
    
        TextRenderer* textInterface;
    
};

#endif /* GraphicsEngine_hpp */
