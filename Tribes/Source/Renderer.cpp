#include "../Headers/Engine/Renderer.hpp"
#include "../Headers/Engine/Quad.hpp"

Renderer::Renderer (int width, int height, SceneCamera* cam) {
    camera = cam;

    // POST PROCESSING
    /*
    // generate framebuffer
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);

    // colour attachment
    glGenTextures   (1, &colourAttachment);
    glBindTexture   (GL_TEXTURE_2D, colourAttachment);
    glTexImage2D    (GL_TEXTURE_2D, 0, GL_RGB, 2880, 1800, 0, GL_RGB,GL_UNSIGNED_BYTE, NULL);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture   (GL_TEXTURE_2D, 0);
    
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colourAttachment, 0);
    
    // depth attachment
    glGenRenderbuffers(1, &RBO);
    glBindRenderbuffer(GL_RENDERBUFFER, RBO);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8,  2880, 1800);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    glFramebufferRenderbuffer (GL_RENDERBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
     */
}

Renderer::~Renderer () {
    glDeleteFramebuffers(1, &FBO);
}

void Renderer::addToScene(Actor* actor) {
    scene.push_back(actor);
}

void Renderer::drawScene(GameState state) {
    /*
    Quad renderedScene = Quad();
    renderedScene.setShader("PostProcess");
    renderedScene.setTexture(colourAttachment);
    
    // render off screen
    glBindFramebuffer (GL_FRAMEBUFFER, FBO);
    glClearColor(0.16, 0.16, 0.16, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    */
    
    // draw
    for (int i = 0; i < scene.size(); i++) {
        scene.at(i)->update(state, camera);
    }
    /*
    // render to screen
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(0.16, 0.16, 0.16, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    
    renderedScene.update(state, camera);
    */
}
