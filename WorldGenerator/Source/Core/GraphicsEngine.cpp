//
//  GraphicsEngine.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "GraphicsEngine.hpp"

GraphicsEngine::GraphicsEngine (float width, float height) {
    camera = new Camera(width / height);
    
    windowWidth = width;
    windowHeight = height;
}

GraphicsEngine::~GraphicsEngine () {
    glDeleteFramebuffers(1, &FBO);
}


void GraphicsEngine::setEffect (Effect e) {
    if (currentEffect != e) {
        frame = new GraphicsObject (
            new QuadGeometry(),
            (e == blur) ? new Material ("pp_gaussianBlur", colourAttachment) : new Material("pp_fadeout", colourAttachment)
        );
        frame->scale = glm::vec3(5.85, 3.25, 1.0);
        currentEffect = e;
    }
}


void GraphicsEngine::initPostProcessing () {
    buildFrameBuffer();

    setEffect(GraphicsEngine::blur);
    
    frame->scale = glm::vec3(5.85, 3.25, 1.0);
}

void GraphicsEngine::buildFrameBuffer  () {
    // generate framebuffer
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
        buildColourBuffer ();
        buildDepthBuffer  ();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GraphicsEngine::buildColourBuffer () {
    glGenTextures   (1, &colourAttachment);
    glBindTexture   (GL_TEXTURE_2D, colourAttachment);
        glTexImage2D    (GL_TEXTURE_2D, 0, GL_RGB, windowWidth*2, windowHeight*2, 0, GL_RGB,GL_UNSIGNED_BYTE, NULL);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture   (GL_TEXTURE_2D, 0);
    
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colourAttachment, 0);
}

void GraphicsEngine::buildDepthBuffer () {
    glGenRenderbuffers      (1, &RBO);
    glBindRenderbuffer      (GL_RENDERBUFFER, RBO);
    glRenderbufferStorage   (GL_RENDERBUFFER, GL_DEPTH32F_STENCIL8, windowWidth*2, windowHeight*2);
    glBindRenderbuffer      (GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
}


void GraphicsEngine::buildShadowDepthBuffer () {
    glGenFramebuffers(1, &depthFBO);
    glGenTextures(1, &depthTexture);
    glBindTexture(GL_TEXTURE_2D, depthTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, windowWidth, windowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GraphicsEngine::prerender() {
    std::sort(scene.begin(), scene.end(),
        [] (GraphicsObject* a, GraphicsObject* b) -> bool {
            return a->position.z < b->position.z;
        }
    );
    
    camera->update();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsEngine::offScreen () {
    // render off screen
    glBindFramebuffer   (GL_FRAMEBUFFER, FBO);
    glClearColor        (0.93f, 0.90f, 0.83f, 1.0f);
    glClear             (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glEnable            (GL_DEPTH_TEST);
    glDepthFunc         (GL_LEQUAL);
}

void GraphicsEngine::onScreen () {
    glBindFramebuffer   (GL_FRAMEBUFFER, 0);
    glClearColor        (0.16, 0.16, 0.16, 1.0);
    glClear             (GL_COLOR_BUFFER_BIT);
    glDisable           (GL_DEPTH_TEST);
    frame->draw         (camera);
}

void GraphicsEngine::renderShadows () {
    // 1. first render to depth map
    glViewport(0, 0, windowWidth, windowHeight);
    glBindFramebuffer(GL_FRAMEBUFFER, depthFBO);
    glClear(GL_DEPTH_BUFFER_BIT);
    
   // ConfigureShaderAndMatrices();
    renderScene();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    // 2. then render scene as normal with shadow mapping (using depth map)
    glViewport(0, 0, windowWidth, windowHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    renderScene();
}

void GraphicsEngine::render() {
    prerender   ();
    offScreen   ();
    renderScene ();
    onScreen    ();
    renderUI    ();
}

void GraphicsEngine::add     (GraphicsObject *object) { scene.push_back(object); }
void GraphicsEngine::addToUI (GraphicsObject *object) { ui.push_back(object); }

void GraphicsEngine::renderScene () { for (GraphicsObject* object : scene) object->draw(camera); }
void GraphicsEngine::renderUI    () { for (GraphicsObject* object : ui)    object->draw(camera); }
