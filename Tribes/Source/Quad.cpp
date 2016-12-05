//
//  Quad.cpp
//  Tribes
//
//  Created by user on 05/12/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/Quad.hpp"

Quad::Quad () {
    std::vector<GLfloat> vertices = {   // Vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
        // Positions   // TexCoords
        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
        1.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        1.0f,  1.0f,  0.0f, 1.0f, 1.0f
    };
    
    shader = (ShaderComponent*)addComponent(new ShaderComponent("PostProcess", BASIC));
    mesh = (MeshComponent*)addComponent(new MeshComponent(vertices));
}

Quad::~Quad () {
    
}

void Quad::setTexture (GLuint tex) {
    texture = tex;
}

void Quad::update(GameState state, SceneCamera *camera) {
    shader->update();
    glBindTexture(GL_TEXTURE_2D, texture);
    mesh->quaddraw(shader, camera, texture);
}
