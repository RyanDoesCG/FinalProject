/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Renderer.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Core/Renderer.hpp"

bool actorDepthComparator (Actor* a, Actor* b) {
    return (a->getPosition().z < b->getPosition().z);
}

Renderer::Renderer (int width, int height) {
    
    setupFrameBufferObject(width, height);
    
    // target quad
    processedScene = Quad();
    processedScene.setShader("PostProcess");
    processedScene.setTexture(colourAttachment);
}

Renderer::~Renderer () {
    glDeleteFramebuffers(1, &FBO);
}

void Renderer::addToScene(Actor* actor) {
    scene.push_back(actor);
}

void Renderer::drawScene(SceneCamera* camera) {
    std::sort(scene.begin(), scene.end(), actorDepthComparator);
    
    // render off screen
    glBindFramebuffer (GL_FRAMEBUFFER, FBO);
    glClearColor(0.16, 0.16, 0.16, 1.0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // draw
    for (int i = 0; i < scene.size(); i++) {
        scene.at(i)->draw (camera);
    }

    // render to screen quad
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    // draw
    processedScene.draw(camera);
}

void Renderer::setupFrameBufferObject(int width, int height) {
    this->width = width;
    this->height = height;
    
    // generate framebuffer
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    
        // generate attachments
        setupColourBuffer();
        setupDepthBuffer();
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Renderer::setupColourBuffer() {
    glGenTextures   (1, &colourAttachment);
    glBindTexture   (GL_TEXTURE_2D, colourAttachment);
    glTexImage2D    (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, NULL);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture   (GL_TEXTURE_2D, 0);
    
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colourAttachment, 0);
}

void Renderer::setupDepthBuffer() {
    glGenRenderbuffers      (1, &RBO);
    glBindRenderbuffer      (GL_RENDERBUFFER, RBO);
    glRenderbufferStorage   (GL_RENDERBUFFER, GL_DEPTH32F_STENCIL8, width, height);
    glBindRenderbuffer      (GL_RENDERBUFFER, 0);
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
}
