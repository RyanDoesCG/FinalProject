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

void GraphicsEngine::initPostProcessing () {
    buildFrameBuffer();

    frame = new GraphicsObject (
        new QuadGeometry(),
        new Material ("pp_fadeout", colourAttachment)
        //new Material ("object_textured", colourAttachment)
    );
    
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
    frame->draw(camera);
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
